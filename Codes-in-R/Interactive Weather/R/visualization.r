generate_weather_plot <- function(weather) {
  data <- data.frame(time = 1:24, temperature = rnorm(24, mean = 20, sd = 5))
  
  ggplot(data, aes(x = time, y = temperature)) +
    geom_line(color = "skyblue", size = 1.5) +
    geom_point(color = "blue", size = 3) +
    labs(title = paste("Weather Forecast: ", weather),
         x = "Time of Day ⏰",
         y = "Temperature (°C) 🌡️") +
    theme_minimal() +
    theme(plot.title = element_text(hjust = 0.5)) +
    theme(axis.title = element_text(size = 12, face = "bold"))
}
