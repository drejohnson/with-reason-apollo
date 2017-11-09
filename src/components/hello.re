let text = ReasonReact.stringToElement;

let handleClick = (_event, _self) => Js.log("clicked!");

let component = ReasonReact.statelessComponent("Hello");

let make = (~message, _children) => {
  ...component,
  render: (self) =>
    <div onClick=(self.handle(handleClick))>
      <h2> (text(message)) </h2>
      <Image
        source="https://fakeimg.pl/400x450/?retina=true"
        resizeMode=Cover
        width=100
        height=100
        backgroundColor="#ccc"
      />
    </div>
};
