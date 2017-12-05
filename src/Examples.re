let getPosition =
  {js|
    type coordinate = {.
      "latitude": float,
      "longitude": float
    };

    type position = {. "coords": coordinate, "timestamp": float};

    type error;

    [@bs.val] external getCurrentPosition : (position => unit, error => unit) => unit =
      "navigator.geolocation.getCurrentPosition";
  |js}
  |> Reason.parseRE
  |> Reason.printRE
  |> String.trim;

let currying =
  {js|
    let fetchVenues = () =>
      fetch("https://coinmap.org/api/v1/venues/")
      |> then_(Response.json)
      |> then_(Models.Decoder.decodeVenues >> resolve);
  |js}
  |> Reason.parseRE
  |> Reason.printRE
  |> String.trim;

let promise =
  {js|
let then_: (
  ('a) => Js.Promise.t('b),
  Js.Promise.t('a)
) => Js.Promise.t('b);
  |js}
  |> String.trim;

let patternMatching =
  {js|
type payload =
  | BadResult(int)
  | GoodResult(string)
  | NoResult;

let data = GoodResult("Product shipped!");

let message =
  switch data {
  | GoodResult(theMessage) => "Success! " ++ theMessage
  | BadResult(errorCode) => "Something's wrong. The error code is: " ++ string_of_int(errorCode)
  };

Warning 8: this pattern-matching is not exhaustive.
Here is an example of a value that is not matched:
NoResult
|js}
  |> String.trim;