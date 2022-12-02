#pragma once

#include <assimp/scene.h>
#include <cassert>
#include <vector>
#include <set>
#include <laml/laml.hpp>

namespace rh {

	struct bone_info {
		u32 parent_idx;
		laml::Mat4 local_matrix;
		laml::Mat4 inv_model_matrix;

		std::string name;
	};

	struct Skeleton {
		static const u32 NullIndex = ~0;

		u32 num_bones;
		std::vector<bone_info> bones;

		// internal
		std::set<std::string_view> unique_bones;
	};

	bool extract_skeleton(const aiScene* scene, Skeleton& skeleton);
	u32 get_bone_index(const Skeleton& skeleton, const std::string_view name);
}