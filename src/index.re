[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

/* let app = ReasonReact.element(BrowserRouter.make([|ReasonReact.element(App.make())|])); */
ReactDOMRe.renderToElementWithId(<App />, "root");

register_service_worker();
