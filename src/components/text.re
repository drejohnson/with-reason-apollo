/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/text.re */
let component = ReasonReact.statelessComponent("Text");

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement("span", ~props={"style": Js.Nullable.from_opt(style)}, children)
};