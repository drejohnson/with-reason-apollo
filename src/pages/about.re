let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

Js.log(component);

let make = (_) => {
  ...component,
  render: (_self) => <View> <Hello message="Hello from about component" /> </View>
};
