[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Describe the result type */
type episode = {. "id": string, "title": string};

type data = {. "episode": episode};

/* Write graphql query */
let query =
  [@bs]
  gql(
    {|
    query episode {
      episode: Episode (id: "cixm6eovajibk0180k40rcoja") {
        id
        title
      }
    }
  |}
  );

/* Pass the above information to the Apollo Client */
module Config = {
  type responseType = data;
  let query = query;
};

/* You can now use it as a JSX call */
module FetchEpisode = Apollo.Client(Config);

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_) => {
  ...component,
  render: (_self) =>
    <View>
      <Hello message="Hello from home component" />
      <FetchEpisode>
        (
          (response) => {
            Js.log(response);
            let title = response##loading ? "" : response##data##episode##title;
            <div> (text(title)) </div>
          }
        )
      </FetchEpisode>
    </View>
};
