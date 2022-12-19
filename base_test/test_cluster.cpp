#include "Cluster.h"
#include "Cluster.cpp"
#include <gtest.h>

TEST(Cluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster a(50,50));
}
 
TEST(Cluster, cant_create_cluster_more_than_MAX_SIZE_CLUSTER)
{
	ASSERT_ANY_THROW(Cluster a(50, MAX_SIZE_CLUSTER + 1));
}

TEST(Cluster, cant_create_cluster_less_than_MIN_SIZE_CLUSTER)
{
	ASSERT_ANY_THROW(Cluster a(50, MIN_SIZE_CLUSTER - 1));
}

TEST(Cluster, cant_create_cluster_with_zero_size)
{
	ASSERT_ANY_THROW(Cluster a(50, 0));
}

TEST(Cluster, cant_create_cluster_with_negative_size)
{
	ASSERT_ANY_THROW(Cluster a(50, -5));
}

TEST(Cluster, can_run_cluster_with_tacts_more_than_MAX_TACTS)
{
	Cluster a(50, 50);
	ASSERT_ANY_THROW(a.clusterJob(0.5, 50, MAX_TACTS + 1));
}

TEST(Cluster, can_run_cluster_with_tacts_less_than_MIN_TACTS)
{
	Cluster a(50, 50);
	ASSERT_ANY_THROW(a.clusterJob(0.5, 50, MIN_TACTS - 1));
}
