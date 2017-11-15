[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

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

/* Describe the result type */
type episode = {. "id": string, "title": string};

type data = {. "episode": episode};

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
            switch response {
            | Loading => <div> (ReasonReact.stringToElement("Loading")) </div>
            | Failed(error) => <div> (ReasonReact.stringToElement(error)) </div>
            | Loaded(result) =>
              <div>
                <Episode
                  key=result##episode##id
                  id=result##episode##id
                  title=result##episode##title
                />
              </div>
            }
        )
      </FetchEpisode>
    </View>
};