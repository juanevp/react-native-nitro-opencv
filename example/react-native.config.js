const path = require("path");
const pak = require("../packages/react-native-nitro-opencv/package.json");

module.exports = {
    // Make autolinking detect local library
    dependencies: {
        [pak.name]: {
            root: path.join(__dirname, "../packages/react-native-nitro-opencv"),
        },
    },
};
