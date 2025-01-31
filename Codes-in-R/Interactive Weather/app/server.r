server <- function(input, output) {
  weather <- reactive({
    generate_weather()
  })
  
  output$current_weather <- renderText({
    paste("Current Weather: ", weather())
  })
  
  output$game_tip <- renderText({
    event <- generate_weather_event(weather())
    paste("Event: ", event)
  })
  
  output$weather_plot <- renderPlot({
    generate_weather_plot(weather())
  })
}
