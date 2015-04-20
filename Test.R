allData <- read.csv("output.tsv", sep="\t", header=TRUE)
data    <- data.frame(ratio = allData$dist_ratio,
                      ans   = as.factor(allData$ans),
                      size  = allData$mess_size)
rm(allData)

slope     <- 0.0001874698
intercept <- 0.1602854
with(data, plot(ratio ~ size, col=ans, pch=20, cex=0.4))
abline(intercept, slope, col=3)

draw_simple_classifier <- function(y_small, x_threshold, y, col=0) {
    segments(0,           y_small, x_threshold,   y_small, col=col)
    segments(x_threshold, y_small, x_threshold,   y,       col=col)
    segments(x_threshold, y,       par("usr")[2], y,       col=col)
}

#MAX_DIST_RATIO       <- 0.37
#MAX_DIST_RATIO_SMALL <- 0.28
#SMALL_THRESHOLD      <- 440
#abline(v=SMALL_THRESHOLD, col=4)
#abline(MAX_DIST_RATIO_SMALL, 0, col=4)
#abline(MAX_DIST_RATIO, 0, col=4)

rect(400, 0.35/2, 410, 0.35, col="lightpink", border=NA)

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- 0.35 / 2
SMALL_THRESHOLD      <- 440

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- MAX_DIST_RATIO / 2
SMALL_THRESHOLD      <- 400
draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col=8)

MAX_DIST_RATIO       <- 0.35
MAX_DIST_RATIO_SMALL <- 0.2
SMALL_THRESHOLD      <- 400
draw_simple_classifier(MAX_DIST_RATIO_SMALL, SMALL_THRESHOLD, MAX_DIST_RATIO, col=9)
