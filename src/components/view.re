/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/view.re */
let component = ReasonReact.statelessComponent("View");

let addKey = (index, item) => <div key=(string_of_int(index))> item </div>;

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement(
      "div",
      ~props={"style": Js.Null_undefined.from_opt(style)},
      children
    )
};
