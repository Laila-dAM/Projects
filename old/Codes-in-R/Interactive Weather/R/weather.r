generate_weather <- function() {
  current_hour <- hour(Sys.time())
  
  if (current_hour %% 4 == 0) {
    return("Storm ⛈️💨🌩️")
  } else if (current_hour %% 3 == 0) {
    return("Heavy Rain 🌧️💦")
  } else if (current_hour %% 2 == 0) {
    return("Light Rain 🌦️🌈")
  } else {
    return("Sunny 🌞☀️🌻")
  }
}
