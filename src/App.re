open BsReactNative;

type state = {counter: int};

type action =
  | Increment
  | Decrement;

let component = ReasonReact.reducerComponent("Cover");

let make = _children => {
  ...component,
  initialState: () => {counter: 0},
  reducer: (action, state) =>
    switch action {
    | Increment =>
      ReasonReact.UpdateWithSideEffects(
        {counter: state.counter + 1},
        (
          (_) =>
            Analytics.counterIncrement(state.counter, state.counter + 1)
            |> ignore
        )
      )
    | Decrement =>
      ReasonReact.UpdateWithSideEffects(
        {counter: state.counter - 1},
        (
          (_) =>
            Analytics.counterDecrement(state.counter, state.counter + 1)
            |> ignore
        )
      )
    },
  render: ({state, send}) =>
    <View>
      <Text>
        (
          ReasonReact.stringToElement("Avo Reason React Native Counter Example")
        )
      </Text>
      <View>
        <Button title="-" onPress=((_) => send(Decrement)) />
        <Text>
          (ReasonReact.stringToElement(string_of_int(state.counter)))
        </Text>
        <Button title="+" onPress=((_) => send(Increment)) />
      </View>
    </View>
};

let default = ReasonReact.wrapReasonForJs(~component, (_) => make([||]));
/* import React, {Component} from 'react';
 *
 * import './App.css';
 * import * as Analytics from './analytics';
 *
 * class App extends Component {
 *   constructor(props) {
 *     super(props);
 *     this.state = {
 *       counter: 0,
 *     };
 *   }
 *
 *   render() {
 *     return (
 *       <div className="App">
 *         <h1 className="Title">Avo Web Counter Example</h1>
 *         <div className="Counter">
 *           <button
 *             className="Button"
 *             onClick={() =>
 *               this.setState((prevState, props) => {
 *                 let nextCounter = prevState.counter - 1;
 *                 Analytics.counterDecrement(prevState.counter, nextCounter);
 *                 return {counter: nextCounter};
 *               })}
 *           >
 *             -
 *           </button>
 *           <div className="Value">{this.state.counter}</div>
 *           <button
 *             className="Button"
 *             onClick={() =>
 *               this.setState((prevState, props) => {
 *                 let nextCounter = prevState.counter + 1;
 *                 Analytics.counterIncrement(prevState.counter, nextCounter);
 *                 return {counter: nextCounter};
 *               })}
 *           >
 *             +
 *           </button>
 *         </div>
 *         <div className="Links">
 *           <a
 *             href="https://preview.avo.sh/?avo=PTAEHEFMDtIJwIYBdIBNQCMCeoCCA3Ae1H3gGcBLQ6UABgDoBGAGlAAUAZAUVwGUvQXACIBJACqgA6uIASoAMK4ASlwBQqpFgAOkUGSRwK0AObrNO0EaRntugGYAbQshsWMhQg-Va4hHXE1QACIAeQd0ADUEBwBXSCDVUFBUSDIAY0MtJCoaIPlCGOgUOBJouMxIO0I4XQwYpCRqUAB3BDJQNIcKNIBrNASk810rb19-QKCAOUhm0CjY+MTk1IyKLJzg-MLi0oXQBDsduoam1vbO7r7UAdAhyyL1SFIizYKi+FARaAzIAFsYJA3FLpTLZJpBSQACxgoBiZA+F167SQ0L0MQwBgQaSQmHqjWgCSWPj88AmYUiZUWSWJ4xwUxmc0phKeANe2w+QkgP3+RSBK1BGwh0JocIRXSRt1RCFQ6GO+MJ1LGpLp5MZCxuNOVwWms3mcQSQA"
 *             target="_blank"
 *             rel="noopener noreferrer"
 *           >
 *             View Event Schema
 *           </a>
 *           {' | '}
 *           <a
 *             href="https://github.com/avohq/avo-example-web-counter"
 *             target="_blank"
 *             rel="noopener noreferrer"
 *           >
 *             View Source Code
 *           </a>
 *         </div>
 *       </div>
 *     );
 *   }
 * }
 *
 * export default App;*/
