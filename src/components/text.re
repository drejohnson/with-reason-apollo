/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/text.re */
let component = ReasonReact.statelessComponent("Text");

let make = (~style=?, children) => {
  ...component,
  render: (_self) => <span ?style> (ReasonReact.arrayToElement(children)) </span>
};
