draw_simple_classifier <- function(y_small, x_threshold, y, col=8) {
    segments(0,           y_small, x_threshold,   y_small, col=col)
    segments(x_threshold, y_small, x_threshold,   y,       col=col)
    segments(x_threshold, y,       par("usr")[2], y,       col=col)
}

args       <- commandArgs(trailingOnly=TRUE)
input.tsv  <- args[1]
output.svg <- args[2]

data       <- read.csv(input.tsv, sep="\t", header=TRUE)
data$Ans   <- as.factor(data$Ans)
data$Guess <- as.factor(data$Guess)
data$Right <- data$Ans == data$Guess

svg(output.svg, width=7, height=7)

with(data, plot(DistRatio ~ Size,
                col=ifelse(data$Right, 8, ifelse(data$Guess == 0, "blue", "red")),
                cex=ifelse(data$Right, 0.3, 1),
                pch=16))

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- 0.228
SMALL_THRESHOLD      <- 450
draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col="red")

invisible(dev.off())
