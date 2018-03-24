[@bs.module] external reactClass : ReasonReact.reactClass = "spectacle-code-slide";

type range = {
  loc: (int, int),
  title: option(string),
  note: option(string)
};

let rangeToJs = (range: range) => {
  "loc": range.loc,
  "title": Js.Null.fromOption(range.title),
  "note": Js.Null.fromOption(range.note)
};

let mapRangesToJs = (rangesOpt) => Js.Option.map((. ranges) => Array.map(rangeToJs, ranges), rangesOpt);

[@bs.obj] external makeProps : (~lang: string, ~code: string, ~transition: array(string), ~ranges: 'a=?, ~showLineNumbers: Js.boolean=?, unit) => _ = "";

let make = (~lang: string, ~code: string, ~ranges: option(array(range))=?, ~showLineNumbers=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~lang, ~code, ~transition=[||], ~ranges=?mapRangesToJs(ranges), ~showLineNumbers?, ()),
    children
  );