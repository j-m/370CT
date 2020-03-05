#pragma once

#define MASTER_RANK 0
#define TAG_TERMINATE 1
#define TAG_EXPECT_LINES 2
#define TAG_MESSAGE_LENGTH 3
#define TAG_MESSAGE 4

extern int processRank;
extern int sizeOfCluster;
