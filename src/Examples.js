// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var $$String = require("bs-platform/lib/js/string.js");
var Reason   = require("reason");

var getPosition = $$String.trim(Reason.printRE(Reason.parseRE("\n    type coordinate = {.\n      \"latitude\": float,\n      \"longitude\": float\n    };\n\n    type position = {. \"coords\": coordinate, \"timestamp\": float};\n\n    type error;\n\n    [@bs.val] external getCurrentPosition : (position => unit, error => unit) => unit =\n      \"navigator.geolocation.getCurrentPosition\";\n  ")));

var currying = $$String.trim(Reason.printRE(Reason.parseRE("\n    let fetchVenues = () =>\n      fetch(\"https://coinmap.org/api/v1/venues/\")\n      |> then_(Response.json)\n      |> then_(Models.Decoder.decodeVenues >> resolve);\n  ")));

var promise = $$String.trim("\nlet then_: (\n  (\'a) => Js.Promise.t(\'b),\n  Js.Promise.t(\'a)\n) => Js.Promise.t(\'b);\n  ");

var patternMatching = $$String.trim("\ntype payload =\n  | BadResult(int)\n  | GoodResult(string)\n  | NoResult;\n\nlet data = GoodResult(\"Product shipped!\");\n\nlet message =\n  switch data {\n  | GoodResult(theMessage) => \"Success! \" ++ theMessage\n  | BadResult(errorCode) => \"Something\'s wrong. The error code is: \" ++ string_of_int(errorCode)\n  };\n\nWarning 8: this pattern-matching is not exhaustive.\nHere is an example of a value that is not matched:\nNoResult\n");

exports.getPosition     = getPosition;
exports.currying        = currying;
exports.promise         = promise;
exports.patternMatching = patternMatching;
/* getPosition Not a pure module */
