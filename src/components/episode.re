let component = ReasonReact.statelessComponent("Episode");

let make = (~style=?, ~title, _children) => {
  ...component,
  render: (_self) => <View ?style> <h1> (ReasonReact.stringToElement(title)) </h1> </View>
};