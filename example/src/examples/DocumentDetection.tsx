import type {SkPoint} from "@shopify/react-native-skia";
import {PaintStyle, PointMode, Skia, vec} from "@shopify/react-native-skia";
import {useEffect} from "react";
import {StyleSheet, Text} from "react-native";
import type {PointVector} from "react-native-nitro-opencv";
import {
    ColorConversionCodes,
    ContourApproximationModes,
    MorphShapes,
    MorphTypes,
    OpenCV,
    RetrievalModes,
} from "react-native-nitro-opencv";
import {Camera, useCameraDevice, useCameraPermission, useSkiaFrameProcessor} from "react-native-vision-camera";
import {useResizePlugin} from "vision-camera-resize-plugin";

const paint = Skia.Paint();
const border = Skia.Paint();

paint.setStyle(PaintStyle.Fill);
paint.setColor(Skia.Color(0x66_e7_a6_49));
border.setStyle(PaintStyle.Fill);
border.setColor(Skia.Color(0xff_e7_a6_49));
border.setStrokeWidth(4);

type Point = {x: number; y: number};

export function DocumentDetection() {
    const device = useCameraDevice("back");
    const {hasPermission, requestPermission} = useCameraPermission();

    const {resize} = useResizePlugin();

    useEffect(() => {
        requestPermission();
    }, [requestPermission]);

    const frameProcessor = useSkiaFrameProcessor(frame => {
        "worklet";

        const ratio = 500 / frame.width;
        const height = frame.height * ratio;
        const width = frame.width * ratio;

        const resized = resize(frame, {
            dataType: "uint8",
            pixelFormat: "bgr",
            scale: {
                height: height,
                width: width,
            },
        });

        const source = OpenCV.objects.bufferToMat(height, width, 3, resized);

        OpenCV.colorConversion.cvtColor(source, source, ColorConversionCodes.COLOR_BGR2GRAY);

        const kernel = OpenCV.objects.createSize(4, 4);
        const blurKernel = OpenCV.objects.createSize(7, 7);
        const structuringElement = OpenCV.imageFiltering.getStructuringElement(MorphShapes.MORPH_ELLIPSE, kernel);

        OpenCV.imageFiltering.morphologyEx(source, source, MorphTypes.MORPH_OPEN, structuringElement);
        OpenCV.imageFiltering.morphologyEx(source, source, MorphTypes.MORPH_CLOSE, structuringElement);
        OpenCV.imageFiltering.GaussianBlur(source, source, blurKernel, 0);
        OpenCV.feature.Canny(source, source, 75, 100);

        const contours = OpenCV.objects.createPointVectorOfVectors();

        OpenCV.shape.findContours(
            source,
            contours,
            RetrievalModes.RETR_LIST,
            ContourApproximationModes.CHAIN_APPROX_SIMPLE
        );

        const contoursMats = contours.toJsValue();

        let greatestPolygon: PointVector | undefined;
        let greatestArea = 0;

        for (let index = 0; index < contoursMats.length; index++) {
            const contour = contours.copyAt(index);
            const area = OpenCV.shape.contourArea(contour, false);

            if (area > 2000 && area > greatestArea) {
                const peri = OpenCV.shape.arcLength(contour, true);
                const approx = OpenCV.objects.createPointVector();
                OpenCV.shape.approxPolyDP(contour, approx, 0.1 * peri, true);
                greatestPolygon = approx;
                greatestArea = area;
            }
        }

        frame.render();

        if (greatestPolygon) {
            const points: Point[] = greatestPolygon.toJsValue();

            if (points.length === 4) {
                const path = Skia.Path.Make();
                const pointsToShow: SkPoint[] = [];

                const lastPointX = (points[3]?.x || 0) / ratio;
                const lastPointY = (points[3]?.y || 0) / ratio;

                path.moveTo(lastPointX, lastPointY);
                pointsToShow.push(vec(lastPointX, lastPointY));

                for (let index = 0; index < 4; index++) {
                    const pointX = (points[index]?.x || 0) / ratio;
                    const pointY = (points[index]?.y || 0) / ratio;

                    path.lineTo(pointX, pointY);
                    pointsToShow.push(vec(pointX, pointY));
                }

                path.close();

                frame.drawPath(path, paint);
                frame.drawPoints(PointMode.Polygon, pointsToShow, border);
            }
        }

        //OpenCV.clearBuffers();
    }, []);

    if (!hasPermission) {
        return <Text>No permission</Text>;
    }

    if (device == null) {
        return <Text>No device</Text>;
    }

    return <Camera style={StyleSheet.absoluteFill} device={device} isActive={true} frameProcessor={frameProcessor} />;
}
