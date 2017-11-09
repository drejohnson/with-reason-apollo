let component = ReasonReact.statelessComponent("Page");

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    <View ?style> (ReasonReact.createDomElement("div", ~props=Js.Obj.empty(), children)) </View>
};
