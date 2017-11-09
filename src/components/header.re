[@bs.module] external logo : string = "../logo.svg";

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header>
      <Image source=logo width=300 height=60 resizeMode=Contain backgroundColor="white" />
      <Navigation />
    </header>
};
