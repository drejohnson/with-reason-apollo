open ReactRouter;

let component = ReasonReact.statelessComponent("Episode");

let make = (~style=?, ~id, ~title, _children) => {
  ...component,
  render: (_self) =>
    <View ?style>
      <h1> (ReasonReact.stringToElement(title)) </h1>
      <NavLink _to={j|/about/$id|j}> (ReasonReact.stringToElement(title)) </NavLink>
    </View>
};