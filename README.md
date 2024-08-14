C - simple_shell

flowchart TD
    A([Start]) --> B[[argv < 2]]
    B -- yes --> C[[Display prompt]]
    C --> D[[Get input using getline]]
    D --> E{Input valid ?}
    E -- no --> 1([Exit shell]):::error
    E -- yes --> F[[Parse input]]
    F --> G{Fork process}
    G -- Error --> 2([Print fork error]):::error
    G -- Child --> H{Has tokens ?}
    G -- Parent --> I[[Wait for child]]
    H -- No --> 3([Exit child]):::error
    H -- yes --> J[[Execute command]]
    J --> 4([Exit child]):::error
    I --> C

    B -- no --> K[[parse arguments]]
    K --> L[[Check if the argument is in the path]]
    L -- no --> 5([Print error]):::error
    L -- yes --> M[[Execute command]]
    M --> N([End])




    classDef error fill:#f96,stroke:#333,stroke-width:2px;
    classDef exit fill:#e96,stroke:#333,stroke-width:2px;
