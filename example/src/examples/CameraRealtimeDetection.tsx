import {PaintStyle, Skia} from "@shopify/react-native-skia";
import {useEffect} from "react";
import {StyleSheet, Text} from "react-native";
import {
    ColorConversionCodes,
    ContourApproximationModes,
    DataTypes,
    OpenCV,
    RetrievalModes,
    type CvRect,
} from "react-native-nitro-opencv";
import {Camera, useCameraDevice, useCameraPermission, useSkiaFrameProcessor} from "react-native-vision-camera";
import {useResizePlugin} from "vision-camera-resize-plugin";

const paint = Skia.Paint();
paint.setStyle(PaintStyle.Fill);
paint.setColor(Skia.Color("red"));

export function CameraRealtimeDetection() {
    const device = useCameraDevice("back");
    const {hasPermission, requestPermission} = useCameraPermission();

    const {resize} = useResizePlugin();

    useEffect(() => {
        requestPermission();
    }, [requestPermission]);

    const frameProcessor = useSkiaFrameProcessor(frame => {
        "worklet";

        const height = frame.height / 4;
        const width = frame.width / 4;

        const resized = resize(frame, {
            scale: {
                width: width,
                height: height,
            },
            pixelFormat: "bgr",
            dataType: "uint8",
        });

        const src = OpenCV.objects.bufferToMat(height, width, 3, resized);
        const dst = OpenCV.objects.createMat(0, 0, DataTypes.Cv8U);

        const lowerBound = OpenCV.objects.createScalar(30, 60, 60);
        const upperBound = OpenCV.objects.createScalar(50, 255, 255);
        OpenCV.colorConversion.cvtColor(src, dst, ColorConversionCodes.COLOR_BGR2HSV);
        OpenCV.core.inRange(dst, lowerBound, upperBound, dst);

        const channels = OpenCV.objects.createMatVector();
        OpenCV.core.split(dst, channels);
        const grayChannel = channels.copyAt(0);

        const contours = OpenCV.objects.createMatVector();
        OpenCV.shape.findContours(
            grayChannel,
            contours,
            RetrievalModes.RETR_TREE,
            ContourApproximationModes.CHAIN_APPROX_SIMPLE
        );

        const contoursMats = contours.toJsValue();
        const rectangles: CvRect[] = [];

        for (let i = 0; i < contoursMats.length; i++) {
            const contour = contours.copyAt(i);
            const area = OpenCV.shape.contourArea(contour, false);

            if (area > 3000) {
                const rect = OpenCV.shape.boundingRect(contour);
                rectangles.push(rect);
            }
        }

        frame.render();

        for (const rect of rectangles) {
            const rectangle = rect.toJsValue();

            frame.drawRect(
                {
                    height: rectangle.height * 4,
                    width: rectangle.width * 4,
                    x: rectangle.x * 4,
                    y: rectangle.y * 4,
                },
                paint
            );
        }

        //OpenCV.clearBuffers(); // REMEMBER TO CLEAN
    }, []);

    if (!hasPermission) {
        return <Text>No permission</Text>;
    }

    if (device == null) {
        return <Text>No device</Text>;
    }

    return <Camera style={StyleSheet.absoluteFill} device={device} isActive={true} frameProcessor={frameProcessor} />;
}
