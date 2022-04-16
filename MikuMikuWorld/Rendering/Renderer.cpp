#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <algorithm>

namespace MikuMikuWorld
{
	Renderer::Renderer() : vBuffer{ VertexBuffer(maxQuads) }
	{
		vBuffer.setup();
		vBuffer.bind();
		quads.reserve(maxQuads);
		init();
	}

	void Renderer::init()
	{
		// order: top-right, bottom-right, bottom-left, top-left
		vPos[0] = DirectX::XMVECTOR{ 0.5f, 0.5f, 0.0f, 1.0f };
		vPos[1] = DirectX::XMVECTOR{ 0.5f, -0.5f, 0.0f, 1.0f };
		vPos[2] = DirectX::XMVECTOR{ -0.5f, -0.5f, 0.0f, 1.0f };
		vPos[3] = DirectX::XMVECTOR{ -0.5f, 0.5f, 0.0f, 1.0f };
	}

	void Renderer::setAnchor(AnchorType type)
	{
		float top = 0.0f;
		float bottom = -1.0f;
		float left = 0.0f;
		float right = 1.0f;

		switch ((uint8_t)type / 3)
		{
		case 1:
			top = 0.5f; bottom = -0.5f;
			break;

		case 2:
			top = 1.0f; bottom = 0.0f;
			break;

		default: break;
		}

		switch ((uint8_t)type % 3)
		{
		case 1: left = -0.5f; right = 0.5f;
			break;

		case 2:
			left = -1.0f; right = 0.0f;
			break;

		default: break;
		}

		vPos[0] = DirectX::XMVECTOR{ right, top, 0.0f, 1.0f };
		vPos[1] = DirectX::XMVECTOR{ right, bottom, 0.0f, 1.0f };
		vPos[2] = DirectX::XMVECTOR{ left, bottom, 0.0f, 1.0f };
		vPos[3] = DirectX::XMVECTOR{ left, top, 0.0f, 1.0f };
	}

	void Renderer::setUVCoords(const Texture& tex, float x1, float x2, float y1, float y2)
	{
		float left = x1 / tex.getWidth();
		float right = x2 / tex.getWidth();
		float top = y1 / tex.getHeight();
		float bottom = y2 / tex.getHeight();

		uvCoords[0] = DirectX::XMVECTOR{ right, top, 0.0f, 0.0f };
		uvCoords[1] = DirectX::XMVECTOR{ right, bottom, 0.0f, 0.0f };
		uvCoords[2] = DirectX::XMVECTOR{ left, bottom, 0.0f, 0.0f };
		uvCoords[3] = DirectX::XMVECTOR{ left, top, 0.0f, 0.0f };
	}

	DirectX::XMMATRIX Renderer::getModelMatrix(const Vector3& pos, const Vector3& rot, const Vector3& scale)
	{
		float rPitch = DirectX::XMConvertToRadians(rot.x);
		float rYaw = DirectX::XMConvertToRadians(rot.y);
		float rRoll = DirectX::XMConvertToRadians(rot.z);

		DirectX::XMMATRIX model = DirectX::XMMatrixIdentity();
		model *= DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);
		model *= DirectX::XMMatrixRotationRollPitchYaw(rPitch, rYaw, rRoll);
		model *= DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);

		return model;
	}

	void Renderer::drawSprite(const Vector2& pos, const float rot, const Vector2& sz, const AnchorType anchor,
		const Texture& tex, int spr, const Color& tint, int z)
	{
		const Sprite& s = tex.sprites[spr];
		drawSprite(pos, rot, sz, anchor, tex, s.getX(), s.getX() + s.getWidth(), s.getY(), s.getY() + s.getHeight(), tint, z);
	}

	void Renderer::drawSprite(const Vector2& pos, const float rot, const Vector2& sz, const AnchorType anchor,
		const Texture& tex, float x1, float x2, float y1, float y2, const Color& tint, int z)
	{
		Vector3 pos3{ pos.x, pos.y, 0.0f };
		Vector3 rot3{ 0, 0, rot };
		Vector3 scale{ sz.x, sz.y, 1.0f };
		DirectX::XMMATRIX model = getModelMatrix(pos3, rot3, scale);
		DirectX::XMVECTOR color{ tint.r, tint.g, tint.b, tint.a };
		setUVCoords(tex, x1, x2, y1, y2);
		setAnchor(anchor);

		pushQuad(vPos, uvCoords, model, color, tex.getID(), z);
	}

	void Renderer::drawRectangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4,
		const Texture& tex, float x1, float x2, float y1, float y2, const Color& tint, int z)
	{
		setUVCoords(tex, x1, x2, y1, y2);
		vPos[0] = DirectX::XMVECTOR{ p4.x, p4.y, 0.0f, 1.0f };
		vPos[1] = DirectX::XMVECTOR{ p2.x, p2.y, 0.0f, 1.0f };
		vPos[2] = DirectX::XMVECTOR{ p1.x, p1.y, 0.0f, 1.0f };
		vPos[3] = DirectX::XMVECTOR{ p3.x, p3.y, 0.0f, 1.0f };
		DirectX::XMVECTOR color{ tint.r, tint.g, tint.b, tint.a };

		pushQuad(vPos, uvCoords, DirectX::XMMatrixIdentity(), color, tex.getID(), z);
	}

	void Renderer::drawRectangle(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, const Texture& tex, float x1, float x2, float y1, float y2,
		const Color& tint, int z)
	{
		setUVCoords(tex, x1, x2, y1, y2);

		DirectX::XMMATRIX model = getModelMatrix(Vector3{}, Vector3{56.0f}, Vector3{1.0f, 1.0f, 1.0f});
		vPos[0] = DirectX::XMVECTOR{ p4.x, p4.y, p4.z, 1.0f };
		vPos[1] = DirectX::XMVECTOR{ p2.x, p2.y, p2.z, 1.0f };
		vPos[2] = DirectX::XMVECTOR{ p1.x, p1.y, p1.z, 1.0f };
		vPos[3] = DirectX::XMVECTOR{ p3.x, p3.y, p3.z, 1.0f };
		DirectX::XMVECTOR color{ tint.r, tint.g, tint.b, tint.a };

		pushQuad(vPos, uvCoords, model, color, tex.getID(), z);
	}

	void Renderer::drawQuad(Vector3 pos, Vector3 rot, Vector3 scale, AnchorType anchor, const Texture& tex, int spr, int z)
	{
		const Sprite& s = tex.sprites[spr];
		DirectX::XMMATRIX model = getModelMatrix(pos, rot, scale);
		DirectX::XMVECTOR color{ 1.0f, 1.0f, 1.0f, 1.0f };
		setUVCoords(tex, s.getX(), s.getX() + s.getWidth(), s.getY(), s.getY() + s.getHeight());
		setAnchor(anchor);

		pushQuad(vPos, uvCoords, model, color, tex.getID(), z);
	}

	void Renderer::drawQuad(Vector3 pos, Vector3 rot, Vector3 scale, AnchorType anchor, const Texture& tex,
		float x1, float x2, float y1, float y2, Color tint, int z)
	{
		DirectX::XMMATRIX model = getModelMatrix(pos, rot, scale);
		DirectX::XMVECTOR color{ tint.r, tint.g, tint.b, tint.a };
		setUVCoords(tex, x1, x2, y1, y2);
		setAnchor(anchor);

		pushQuad(vPos, uvCoords, model, color, tex.getID(), z);
	}

	void Renderer::pushQuad(const std::array<DirectX::XMVECTOR, 4>& pos, const std::array<DirectX::XMVECTOR, 4>& uv,
		const DirectX::XMMATRIX& m, const DirectX::XMVECTOR& col, int tex, int z)
	{
		Quad q;
		q.matrix = m;
		q.texture = tex;
		q.zIndex = z;
		for (int i = 0; i < 4; ++i)
		{
			q.vertices[i].position = vPos[i];
			q.vertices[i].color = col;
			q.vertices[i].uv = uvCoords[i];
		}

		quads.push_back(q);

		++numQuads;
		numVertices += 4;
		numIndices += 6;
	}

	void Renderer::resetRenderStats()
	{
		numIndices = 0;
		numVertices = 0;
		numQuads = 0;
	}

	void Renderer::bindTexture(int tex)
	{
		texID = tex;
		glBindTexture(GL_TEXTURE_2D, texID);
	}

	void Renderer::beginBatch()
	{	
		batchStarted = true;
		vBuffer.resetBufferPos();
		quads.clear();
		resetRenderStats();
	}

	void Renderer::endBatch()
	{
		numBatchVertices = numVertices;
		numBatchQuads = numQuads;

		batchStarted = false;
		if (!quads.size())
			return;

		std::sort(quads.begin(), quads.end());
		glActiveTexture(GL_TEXTURE0);
		bindTexture(quads[0].texture);

		int vertexCount = 0;

		for (const auto& q : quads)
		{
			if (texID != q.texture || vertexCount + 4 >= vBuffer.getCapacity())
			{
				vBuffer.uploadBuffer();
				flush();
				vBuffer.resetBufferPos();
				resetRenderStats();

				vertexCount = 0;

				bindTexture(q.texture);
			}

			vBuffer.pushBuffer(q);
			vertexCount += 4;
		}

		//vBuffer.resetBufferPos();
		vBuffer.uploadBuffer();
		flush();

		batchStarted = false;
	}

	void Renderer::flush()
	{
		vBuffer.flushBuffer();
	}
}