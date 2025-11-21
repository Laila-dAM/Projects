fluidPage(
  titlePanel("Interactive Weather System for Games 🌤️✨"),
  
  sidebarLayout(
    sidebarPanel(
      textOutput("current_weather"),
      actionButton("generate_event", "Generate Event ⚡", icon = icon("bolt"), class = "btn-primary"),
      hr(),
      textOutput("game_tip")
    ),
    
    mainPanel(
      plotOutput("weather_plot"),
      h4("Stay prepared, adventurer! 💪")
    )
  )
)