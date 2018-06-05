module type T_ = {
  let counterDecrement : (~oldValue: int, ~newValue: int) => unit;
  
  let counterIncrement : (~oldValue: int, ~newValue: int) => unit;
  
  let setup_ : (~options: {. "useProductionKey": bool, 
    "validateProperties": bool}, unit) => unit;
  
  let setSystemProps_ : (unit) => unit;
  
  
};

[@bs.module "./analytics.js"]
external counterDecrement : (int, int) => unit = "";

let counterDecrement = (~oldValue: int, ~newValue: int) =>
  counterDecrement(oldValue, newValue);

[@bs.module "./analytics.js"]
external counterIncrement : (int, int) => unit = "";

let counterIncrement = (~oldValue: int, ~newValue: int) =>
  counterIncrement(oldValue, newValue);

[@bs.module "./analytics.js"]
external setup_ : ({. "useProductionKey": bool, "validateProperties": bool},
                    Js.t('a)) => unit = "";

let setup_ =
  (~options: {. "useProductionKey": bool, "validateProperties": bool}, ()) =>
  setup_({"useProductionKey": options##useProductionKey, "validateProperties": options##validateProperties},
    Js.Obj.empty());

[@bs.module "./analytics.js"]
external setSystemProps_ : (Js.t('a)) => unit = "";

let setSystemProps_ = () => setSystemProps_(Js.Obj.empty());

