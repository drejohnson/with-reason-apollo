open ReactRouter;

let renderHome = (jsProps) => <Home _match=jsProps##_match />;

let renderAbout = (_) => <About />;

let renderDisplay = (jsProps) => <Display _match=jsProps##_match />;

let renderNotFound = (_) => <NotFound />;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    ReasonReact.element(
      BrowserRouter.make([|
        ReasonReact.cloneElement(
          <div>
            <Header />
            <Switch>
              <Route path="/" exact=true component=renderHome />
              <Route path="/about" exact=true component=renderAbout />
              <Route path="/display/:id" exact=true component=renderDisplay />
              <Route component=renderNotFound />
            </Switch>
          </div>,
          ~props=Js.Obj.empty(),
          [||]
        )
      |])
    )
};