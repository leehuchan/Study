#pragma once
class ArkBlock : public RectCollider
{
public:
	enum class Type
	{
		NONE,
		BLOCKBar,
		PLAYER,
		ITEM,

		TYPE_COUNT
	};

	ArkBlock();
	~ArkBlock();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetType(ArkBlock::Type type) { _curType = type; }
	ArkBlock::Type GetBlockType() { return _curType; }

private:
	vector<HBRUSH> _brushes;
	ArkBlock::Type _curType = Type::NONE;

};

