#include "GamePart.h"
namespace tzw
{

	Attachment::Attachment(vec3 thePos, vec3 n, vec3 up, GamePart * parent)
	{
		m_pos = thePos;
		m_normal = n;
		m_up = up;
		m_bearPart = nullptr;
		m_parent = parent;
	}

	Attachment::Attachment()
	{
		m_bearPart = nullptr;
	}

	void Attachment::getAttachmentInfo(vec3 & pos, vec3 & N, vec3 & up)
	{
		auto mat = m_parent->getNode()->getLocalTransform();
		vec4 a_pos = vec4(m_pos, 1.0);
		vec4 a_n = vec4(m_normal, 0.0);
		vec4 a_up = vec4(m_up, 0.0);
		pos = mat.transofrmVec4(a_pos).toVec3();
		N = mat.transofrmVec4(a_n).toVec3();
		up = mat.transofrmVec4(a_up).toVec3();
	}

	void Attachment::getAttachmentInfoWorld(vec3 & pos, vec3 & N, vec3 & up)
	{
		auto mat = m_parent->getNode()->getTransform();
		vec4 a_pos = vec4(m_pos, 1.0);
		vec4 a_n = vec4(m_normal, 0.0);
		vec4 a_up = vec4(m_up, 0.0);
		pos = mat.transofrmVec4(a_pos).toVec3();
		N = mat.transofrmVec4(a_n).toVec3();
		up = mat.transofrmVec4(a_up).toVec3();
	}

	Matrix44 Attachment::getAttachmentInfoMat44()
	{
		vec3 right = vec3::CrossProduct(m_normal, m_up);
		Matrix44 transformForAttachPoint;
		auto data = transformForAttachPoint.data();
		data[0] = right.x;
		data[1] = right.y;
		data[2] = right.z;
		data[3] = 0.0;

		data[4] = m_up.x;
		data[5] = m_up.y;
		data[6] = m_up.z;
		data[7] = 0.0;
		//right hand
		data[8] = -m_normal.x;
		data[9] = -m_normal.y;
		data[10] = -m_normal.z;
		data[11] = 0.0;

		data[12] = m_pos.x;
		data[13] = m_pos.y;
		data[14] = m_pos.z;
		data[15] = 1.0;
		return transformForAttachPoint;
	}

	Drawable3D * GamePart::getNode() const
	{
		return m_node;
	}

	void GamePart::setNode(Drawable3D * node)
	{
		m_node = node;
	}

	PhysicsShape * GamePart::getShape()
	{
		return m_shape;
	}

	Attachment * GamePart::findProperAttachPoint(Ray ray, vec3 &attachPosition, vec3 &Normal, vec3 & up)
	{
		return false;
	}

	void GamePart::attachTo(Attachment * attach)
	{
	}

	void GamePart::attachToFromOtherIsland(Attachment * attach, BearPart * bearing)
	{
	}

}