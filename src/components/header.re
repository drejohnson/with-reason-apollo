[@bs.module] external logo : string = "../logo.svg";

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header>
      <Image source=logo width=80 height=80 resizeMode=Contain backgroundColor="white" />
      <Navigation />
    </header>
};