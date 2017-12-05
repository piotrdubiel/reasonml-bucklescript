type theme;

[@bs.deriving {jsConverter: newType}]
type colorsDefinition = {
  primary: string,
  secondary: string,
  tertiary: string,
  quarternary: string
};

[@bs.deriving {jsConverter: newType}]
type fontDefinition = {
  name: string,
  googleFont: bool,
  styles: array(string)
};

type fontsDefinition = {
  primary: fontDefinition,
  secondary: fontDefinition
};

let fontsDefinitionToJs = (fonts) => {
  "primary": fontDefinitionToJs(fonts.primary),
  "secondary": fontDefinitionToJs(fonts.secondary)
};

[@bs.module "spectacle/lib/themes/default"]
external _createTheme :
  (abs_colorsDefinition, {. "primary": abs_fontDefinition, "secondary": abs_fontDefinition}) =>
  theme =
  "default";

let createTheme = (colors, fonts) =>
  _createTheme(colorsDefinitionToJs(colors), fontsDefinitionToJs(fonts));

module Deck = {
  [@bs.deriving jsConverter]
  type progress = [ | `pacman | `bar | `number | `none];
  [@bs.deriving jsConverter]
  type transition = [ | `slide | `zoom | `fade | `spin];
  [@bs.module "spectacle"] external deckReactClass : ReasonReact.reactClass = "Deck";
  let make =
      (
        ~transition: array(transition)=[|`slide|],
        ~progress: progress=`pacman,
        ~theme: option(theme)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=deckReactClass,
      ~props={
        "transition": Array.map(transitionToJs, transition),
        "progress": progressToJs(progress),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Slide = {
  [@bs.module "spectacle"] external slideReactClass : ReasonReact.reactClass = "Slide";
  let make = (~bgColor: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=slideReactClass,
      ~props={"bgColor": Js.Nullable.from_opt(bgColor)},
      children
    );
};

module Heading = {
  [@bs.module "spectacle"] external headingReactClass : ReasonReact.reactClass = "Heading";
  let make =
      (
        ~size: int=1,
        ~fit: bool=false,
        ~lineHeight: int=1,
        ~textColor: option(string)=?,
        ~caps: bool=false,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=headingReactClass,
      ~props={
        "size": size,
        "fit": Js.Boolean.to_js_boolean(fit),
        "lineHeight": lineHeight,
        "textColor": Js.Nullable.from_opt(textColor),
        "caps": Js.Boolean.to_js_boolean(caps)
      },
      children
    );
};

module List = {
  [@bs.module "spectacle"] external listReactClass : ReasonReact.reactClass = "List";
  let make =
      (~ordered: bool=false, ~reversed: bool=false, ~start: int=1, ~type_: string="1", children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listReactClass,
      ~props={
        "ordered": Js.Boolean.to_js_boolean(ordered),
        "reversed": Js.Boolean.to_js_boolean(reversed),
        "start": start,
        "type": type_
      },
      children
    );
};

module ListItem = {
  [@bs.module "spectacle"] external listItemReactClass : ReasonReact.reactClass = "ListItem";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=listItemReactClass, ~props=Js.Obj.empty(), children);
};

module Appear = {
  [@bs.module "spectacle"] external appearReactClass : ReasonReact.reactClass = "Appear";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=appearReactClass, ~props=Js.Obj.empty(), children);
};

/* alt	PropTypes.string	Set the alt property of the image
   display	PropTypes.string	Set the display style property of the image
   height	PropTypes.string or PropTypes.number	Supply a height to the image
   src	PropTypes.string	Image src
   width	PropTypes.string or PropTypes.number */
module Image = {
  [@bs.module "spectacle"] external imageReactClass : ReasonReact.reactClass = "Image";
  let make =
      (~alt: string, ~src: string, ~width: option(string)=?, ~height: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=imageReactClass,
      ~props={
        "alt": alt,
        "width": Js.Nullable.from_opt(width),
        "height": Js.Nullable.from_opt(height),
        "src": src
      },
      children
    );
};

module Notes = {
  [@bs.module "spectacle"] external notesReactClass : ReasonReact.reactClass = "Notes";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=notesReactClass, ~props=Js.Obj.empty(), children);
};

module BlockQuote = {
  [@bs.module "spectacle"] external blockQuoteReactClass : ReasonReact.reactClass = "BlockQuote";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=blockQuoteReactClass, ~props=Js.Obj.empty(), children);
};

module Quote = {
  [@bs.module "spectacle"] external quoteReactClass : ReasonReact.reactClass = "Quote";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=quoteReactClass, ~props=Js.Obj.empty(), children);
};

module Cite = {
  [@bs.module "spectacle"] external citeReactClass : ReasonReact.reactClass = "Cite";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=citeReactClass, ~props=Js.Obj.empty(), children);
};

module Layout = {
  [@bs.module "spectacle"] external layoutReactClass : ReasonReact.reactClass = "Layout";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=layoutReactClass, ~props=Js.Obj.empty(), children);
};

module Fit = {
  [@bs.module "spectacle"] external fitReactClass : ReasonReact.reactClass = "Fit";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=fitReactClass, ~props=Js.Obj.empty(), children);
};

module Fill = {
  [@bs.module "spectacle"] external fillReactClass : ReasonReact.reactClass = "Fill";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=fillReactClass, ~props=Js.Obj.empty(), children);
};

module Text = {
  [@bs.module "spectacle"] external textReactClass : ReasonReact.reactClass = "Text";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=textReactClass, ~props=Js.Obj.empty(), children);
};