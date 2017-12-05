[@bs.module] external codeSlideReactClass : ReasonReact.reactClass = "spectacle-code-slide";

type range = {
  loc: (int, int),
  title: option(string),
  note: option(string)
};

let rangeToJs = (range: range) => {
  "loc": range.loc,
  "title": Js.Null.from_opt(range.title),
  "note": Js.Null.from_opt(range.note)
};

let make = (~lang: string, ~code: string, ~ranges: array(range), ~showLineNumbers=true, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=codeSlideReactClass,
    ~props={
      "lang": lang,
      "code": code,
      "transition": [||],
      "ranges": Array.map(rangeToJs, ranges),
      "showLineNumbers": Js.Boolean.to_js_boolean(showLineNumbers)
    },
    children
  );