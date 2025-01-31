generate_weather_event <- function(current_weather) {
  if (current_weather == "Storm ⛈️💨🌩️") {
    return("⚡ A mighty storm has struck! Take cover! 🏚️🌪️")
  } else if (current_weather == "Heavy Rain 🌧️💦") {
    return("🌧️ It’s raining cats and dogs! Get ready for slippery roads! 🐾💧")
  } else if (current_weather == "Light Rain 🌦️🌈") {
    return("☔ A light rain falls, perfect for a calm walk in the park 🌸🌿")
  } else {
    return("🌞 A bright and sunny day! The world is shining! 🌻🏞️")
  }
}
