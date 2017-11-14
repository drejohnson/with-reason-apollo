[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Describe the result type */
type episode = {. "id": string, "title": string};

type data = {. "episode": episode};

/* Write graphql query */
let query =
  [@bs]
  gql(
    {|
    query episode($id: ID) {
      episode: Episode (id: $id) {
        id
        title
      }
    }
  |}
  );

let variables = {"id": "cixm6eovajibk0180k40rcoja"};

/* Pass the above information to the Apollo Client */
module Config = {
  type responseType = data;
  type variables = {. "id": string};
};

/* You can now use it as a JSX call */
module FetchEpisode = Apollo.Client(Config);

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <View>
      <Hello message="Hello from home component" />
      <FetchEpisode query variables>
        (
          (response) =>
            response##loading ?
              <div> (ReasonReact.stringToElement("Loading")) </div> :
              <div>
                <Episode
                  key=response##data##episode##id
                  id=response##data##episode##id
                  title=response##data##episode##title
                />
              </div>
        )
      </FetchEpisode>
    </View>
};