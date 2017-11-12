[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Describe the result type */
type episodes = {. "id": string, "title": string};

type data = {. "allEpisodes": array(episodes)};

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

/* Pass the above information to the Apollo Client */
module Config = {
  type responseType = data;
  let query = query;
};

/* You can now use it as a JSX call */
module FetchEpisodes = Apollo.Client(Config);

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_) => {
  ...component,
  render: (_self) =>
    <View>
      <Hello message="Hello from about component" />
      <FetchEpisodes>
        (
          (response) =>
            response##loading ?
              <div> (ReasonReact.stringToElement("Loading")) </div> :
              <div>
                (
                  ReasonReact.arrayToElement(
                    Array.map(
                      (episode) => <Episode key=episode##id title=episode##title />,
                      response##data##allEpisodes
                    )
                  )
                )
              </div>
        )
      </FetchEpisodes>
    </View>
};