[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Write graphql query */
let query =
  [@bs] gql({|
  query allEpisodes {
    allEpisodes {
      id
      title
    }
  }
  |});

/* Describe the result type */
type episodes = {. "id": string, "title": string};

type data = {. "allEpisodes": array(episodes)};

/* Pass the return type of the query to a module containing a type named `responseType` */
module Config = {
  type responseType = data;
  type variables;
};

/* You can now use it as a JSX call */
module FetchEpisodes = Apollo.Client(Config);

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (~_match, _children) => {
  ...component,
  render: (_self) => {
    Js.log(_match##params##id);
    <View>
      <Hello message="Hello from home component" />
      <FetchEpisodes query>
        (
          (response) =>
            switch response {
            | Loading => <div> (ReasonReact.stringToElement("Loading")) </div>
            | Failed(error) => <div> (ReasonReact.stringToElement(error)) </div>
            | Loaded(result) =>
              <div>
                (
                  ReasonReact.arrayToElement(
                    Array.map(
                      (episode) => <Episode key=episode##id id=episode##id title=episode##title />,
                      result##allEpisodes
                    )
                  )
                )
              </div>
            }
        )
      </FetchEpisodes>
    </View>
  }
};