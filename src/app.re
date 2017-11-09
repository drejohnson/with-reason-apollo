open ReactRouter;

let renderHome = (_) => <Home />;

let renderAbout = (_) => <About />;

let renderNotFound = (_) => <NotFound />;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    ReasonReact.element(
      BrowserRouter.make([|
        ReasonReact.cloneElement(
          <div className="App">
            <Header />
            <Switch>
              <Route path="/" exact=true component=renderHome />
              <Route path="/about" component=renderAbout />
              <Route component=renderHome />
            </Switch>
          </div>,
          ~props=Js.Obj.empty(),
          [||]
        )
      |])
    )
};
