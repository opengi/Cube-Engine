#ifndef TZW_MARCHINGCUBES_H
#define TZW_MARCHINGCUBES_H

#include "../../Engine/EngineDef.h"
#include "../../Math/vec4.h"
#include "../../Mesh/Mesh.h"
#include "Mesh/VertexData.h"

namespace tzw {
	struct voxelInfo;
	struct VoxelVertex
	{
		vec3 vertex;
		MatBlendInfo matInfo;
	};
class MarchingCubes :public Singleton<MarchingCubes>
{
public:
    void generateWithoutNormal(vec3 basePoint,Mesh * mesh, int ncellsX, int ncellsY, int ncellsZ, voxelInfo * srcData, float minValue = -1, int lodLevel = 0);
    MarchingCubes();
};

} // namespace tzw

#endif // TZW_MARCHINGCUBES_H
