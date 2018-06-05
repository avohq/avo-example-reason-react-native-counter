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
    switch (action) {
    | Increment =>
      ReasonReact.UpdateWithSideEffects(
        {counter: state.counter + 1},
        (
          _self =>
            AnalyticsRe.counterIncrement(
              ~oldValue=state.counter,
              ~newValue=state.counter + 1,
            )
            |> ignore
        ),
      )
    | Decrement =>
      ReasonReact.UpdateWithSideEffects(
        {counter: state.counter - 1},
        (
          _self =>
            AnalyticsRe.counterDecrement(
              ~oldValue=state.counter,
              ~newValue=state.counter + 1,
            )
            |> ignore
        ),
      )
    },
  render: ({state, send}) =>
    <View>
      <Text>
        (ReasonReact.string("Avo Reason React Native Counter Example"))
      </Text>
      <View>
        <Button title="-" onPress=(_ => send(Decrement)) />
        <Text> (ReasonReact.string(string_of_int(state.counter))) </Text>
        <Button title="+" onPress=(_ => send(Increment)) />
      </View>
    </View>,
};

let default = ReasonReact.wrapReasonForJs(~component, _ => make([||]));
