import {AppRegistry} from 'react-native';

import Analytics from './src/analytics';
import App from './src/App.bs.js';

Analytics.setup_({useProductionKey: !__DEV__, validateProperties: __DEV__});

AppRegistry.registerComponent('ReasonCounter', () => App);
