open BsSpectacle;

let component = ReasonReact.statelessComponent("Presentation");

let theme =
  Theme.(
    createTheme(
      {primary: "#db4d3f", secondary: "black", tertiary: "white", quarternary: "white"},
      {
        primary: {name: "Roboto Slab", googleFont: true, styles: [|"300"|]},
        secondary: {name: "Roboto", googleFont: true, styles: [|"300"|]},
        tertiary: simpleFont("monospace")
      }
    )
  );

let s = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Deck progress=`bar theme>
      <Slide>
        <Heading> "ReasonML" </Heading>
        <Heading> "+" </Heading>
        <Heading> "BuckleScript" </Heading>
        <Heading> "=" </Heading>
        <Appear> <Heading> {js|🎉|js} </Heading> </Appear>
      </Slide>
      <Slide bgColor="tertiary">
        <BlockQuote>
          <Quote> {js|Javascript is great, because of the ecosystem,|js} </Quote>
          <Appear>
            <Quote> {js|not because it’s maintainable out-of-the-box.|js} </Quote>
          </Appear>
        </BlockQuote>
      </Slide>
      <Slide bgColor="tertiary">
        <Layout>
          <Fit>
            <BlockQuote> <Quote> "Flowtype" </Quote> <Quote> "TypeScript" </Quote> </BlockQuote>
          </Fit>
          <Fill />
          <Fit>
            <BlockQuote>
              <Quote> "Elm" </Quote>
              <Quote> "ClojureScript" </Quote>
              <Quote> "PureScript" </Quote>
            </BlockQuote>
          </Fit>
        </Layout>
      </Slide>
      <Slide bgColor="tertiary">
        <Image src="images/functional-programming.jpg" height="700" alt="functionl programming" />
      </Slide>
      <Slide bgColor="tertiary">
        <Heading textColor="primary"> "Types are useful" </Heading>
        <Heading size=3>
          {js|when composing curried functions, it’s easy to make a mistake.|js}
        </Heading>
      </Slide>
      <CodeSlide
        code=Examples.currying
        lang="reason"
        ranges=[|
          {loc: (0, 1), title: None, note: Some("function to make api request & decode json")},
          {loc: (1, 2), title: None, note: Some("make request, returns Promise of response")},
          {loc: (2, 3), title: None, note: Some("decode JSON, returns Promise of JSON object")},
          {loc: (3, 4), title: None, note: Some("convert generic JSON into some model object")}
        |]
      />
      <CodeSlide
        code=Examples.promise
        lang="reason"
        ranges=[|
          {
            loc: (1, 2),
            title: None,
            note:
              Some(
                "function to transform value of type a' to Promise of type b' after previous promise resolved"
              )
          },
          {loc: (2, 3), title: None, note: Some("previous promise wrapping type a'")},
          {loc: (3, 4), title: None, note: Some("new promise with value of type b'")}
        |]
      />
      <Slide bgColor="tertiary">
        <Heading size=3> "React is functional" </Heading>
        <List>
          <Appear> <ListItem> "Components as functions of state" </ListItem> </Appear>
          <Appear> <ListItem> "preferably immutable" </ListItem> </Appear>
          <Appear> <ListItem> "declarative" </ListItem> </Appear>
          <Appear>
            <ListItem> "emphasis on first-class and higher-order functions" </ListItem>
          </Appear>
        </List>
      </Slide>
      <Slide bgColor="tertiary"> <Image src="images/bloomberg.png" alt="Bloomberg" /> </Slide>
      <Slide bgColor="#ab5ea3"> <Heading> "BuckleScript" </Heading> </Slide>
      <Slide bgColor="tertiary">
        <Heading textColor="secondary"> "Compiles OCaml to JavaScript" </Heading>
      </Slide>
      <Slide bgColor="tertiary">
        <Heading textColor="secondary"> "Why OCaml?" </Heading>
        <List>
          <Appear> <ListItem> "Sound type system." </ListItem> </Appear>
          <Appear> <ListItem> "Strong type inference." </ListItem> </Appear>
          <Appear>
            <ListItem> "Expressive type features, like variants, modules & objects." </ListItem>
          </Appear>
        </List>
      </Slide>
      <Slide bgColor="tertiary">
        <Heading size=3 textColor="secondary"> "BuckleScript features" </Heading>
        <List>
          <Appear> <ListItem> "dead code elimination," </ListItem> </Appear>
          <Appear> <ListItem> "compile-time optimizations," </ListItem> </Appear>
          <Appear> <ListItem> "readable & tiny JS output," </ListItem> </Appear>
          <Appear> <ListItem> "preservation of code structure," </ListItem> </Appear>
          <Appear> <ListItem> "fast iteration loop." </ListItem> </Appear>
        </List>
      </Slide>
      <CodeSlide
        code=Examples.getPosition
        lang="reason"
        ranges=[|
          {
            loc: (16, 17),
            title: None,
            note: Some("We are wrapping \"navigator.geolocation.getCurrentPosition\"")
          },
          {
            loc: (15, 16),
            title: None,
            note: Some("We are providing two callbacks: for success and for failure.")
          },
          {
            loc: (14, 15),
            title: None,
            note: Some("This is a BuckleScript macro to mark this function as global.")
          },
          {loc: (12, 13), title: None, note: Some("Error is just some abstract type.")},
          {
            loc: (6, 11),
            title: None,
            note: Some("Position is an object with coordinate and timestamp.")
          },
          {
            loc: (0, 5),
            title: None,
            note: Some("Coordinate is an object with latitude and longitude.")
          }
        |]
      />
      <Slide bgColor="tertiary">
        <BlockQuote>
          <Quote> {js|ReasonML is just JavaScript-like syntax for OCaml|js} </Quote>
        </BlockQuote>
      </Slide>
      <CodeSlide
        code=Examples.patternMatching
        lang="reason"
        ranges=[|
          {loc: (0, 4), title: None, note: Some("payload is some variant type")},
          {loc: (5, 6), title: None, note: Some("we construct payload")},
          {
            loc: (8, 9),
            title: None,
            note: Some("to construct a message with pattern match on data")
          },
          {loc: (9, 10), title: None, note: Some("if it's GoodResult, use theMessage")},
          {loc: (10, 11), title: None, note: Some("if it's BadResult, use errorCode")},
          {
            loc: (13, 16),
            title: None,
            note: Some("compiler will warn us about missing NoResult variant")
          }
        |]
      />
      <Slide> <Heading> "Thanks" </Heading> </Slide>
    </Deck>
};