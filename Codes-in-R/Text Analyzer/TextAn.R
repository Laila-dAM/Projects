text <- tolower(readLines())
words <- unlist(strsplit(text, "\\s+"))
words <- words[words != ""]

num_words <- length(words)
num_sentences <- length(unlist(strsplit(text, "[.!?]")))
unique_words <- length(unique(words))
word_freq <- table(words)
flesch_index <- 206.835 - 1.015 * (num_words / num_sentences) - 84.6 * (sum(nchar(words)) / num_words)
cat("Total Words: ", num_words, "\n")
cat("Total Sentences: ", num_sentences, "\n")
cat("Unique Words: ", unique_words, "\n")
cat("Flesch Readability Index: ", flesch_index, "\n")
barplot(word_freq[order(-word_freq)][1:10], main = "Most Frequent Words", xlab = "Words", ylab = "Frequency", col = "lightblue")
