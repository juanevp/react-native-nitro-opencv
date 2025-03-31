import {useState} from "react";
import {Button, Image, SafeAreaView} from "react-native";
import {launchImageLibrary, type Asset} from "react-native-image-picker";
import {BorderTypes, DataTypes, OpenCV} from "react-native-nitro-opencv";
import {useRunOnJS, useWorklet} from "react-native-worklets-core";

export function ImageExample() {
    const [photo, setPhoto] = useState<Asset | null>(null);
    const [result, setResult] = useState<string>("");

    const getImageFromGallery = async () => {
        const res = await launchImageLibrary({
            mediaType: "photo",
            includeBase64: true,
        });
        setPhoto(res.assets?.at(0) || null);
    };

    const setImage = useRunOnJS((data: string) => {
        setResult(data);
    }, []);

    const worklet = useWorklet("default", () => {
        "worklet";
        if (photo?.base64) {
            const src = OpenCV.objects.base64ToMat(photo.base64);
            const dst = OpenCV.objects.createMat(0, 0, DataTypes.Cv8U);
            const kernel = OpenCV.objects.createSize(20, 20);
            const point = OpenCV.objects.createPoint(0, 0);

            OpenCV.imageFiltering.blur(src, dst, kernel, point, BorderTypes.BORDER_DEFAULT);
            const dstResult = dst.toJsValue();

            setImage(dstResult.base64);

            //OpenCV.clearBuffers(); // IMPORTANT
        }
    });

    return (
        // eslint-disable-next-line react-native/no-inline-styles
        <SafeAreaView style={{backgroundColor: "white", flex: 1}}>
            <Button title="Select photo" onPress={getImageFromGallery} />
            <Button title="Process" onPress={() => worklet()} />

            {result && <Image source={{uri: "data:image/png;base64," + result}} height={530} width={390} />}
        </SafeAreaView>
    );
}
