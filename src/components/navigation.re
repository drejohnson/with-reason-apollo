open ReactRouter;

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Navigation");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav>
      <NavLink activeClassName="active" _to="/"> (text("Home")) </NavLink>
      <NavLink activeClassName="active" _to="/about"> (text("About")) </NavLink>
    </nav>
};
