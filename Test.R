allData <- read.csv("output.tsv", sep="\t", header=TRUE)
data    <- data.frame(ratio = allData$dist_ratio,
                      size  = allData$mess_size)
rm(allData)

slope     <- 0.0001874698
intercept <- 0.1602854

data$ans <- as.factor(intercept + slope * data$size > data$ratio)

with(data, plot(ratio ~ size, col = ans))

abline(intercept, slope)
