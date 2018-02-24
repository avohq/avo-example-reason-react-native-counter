[@bs.module "./analytics.js"]
external counterIncrement : (int, int) => unit = "";

let counterIncrement = (~oldValue: int, ~newValue: int) =>
  counterIncrement(oldValue, newValue);

[@bs.module "./analytics.js"]
external counterDecrement : (int, int) => unit = "";

let counterDecrement = (~oldValue: int, ~newValue: int) =>
  counterDecrement(oldValue, newValue);

