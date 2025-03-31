const path = require('path');
const { getDefaultConfig, mergeConfig } = require('@react-native/metro-config');
//const pkg = require('../package.json');

const root = path.resolve(__dirname, '..');

/**
 * Metro configuration
 * https://facebook.github.io/metro/docs/configuration
 *
 * @type {import('metro-config').MetroConfig}
 */
module.exports = mergeConfig(getDefaultConfig(__dirname), {
  watchFolders: [root],
  projectRoot: __dirname,
});
