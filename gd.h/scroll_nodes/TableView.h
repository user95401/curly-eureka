#ifndef __TABLEVIEW_H__
#define __TABLEVIEW_H__

#include <gd.h>

namespace gd {

	class CCScrollLayerExt;
	class CCScrollLayerExtDelegate;
	class CCIndexPath;
	class TableViewDelegate;
	class TableViewDataSource;
	
	typedef enum {
		//idk what goes here
	} TableViewCellEditingStyle;

	class TableView : public CCScrollLayerExt, public CCScrollLayerExtDelegate {
	public:
		bool m_bTouchDown2;
		PAD(4)
		cocos2d::CCPoint m_obTouchStartPosition2;	// 0x170
		cocos2d::CCPoint m_obUnknown2;	// 0x178
		cocos2d::CCPoint m_obTouchPosition2;	// 0x180
		PAD(4)
		bool m_bTouchMoved;
		PAD(3)
		cocos2d::CCArray* m_pCellArray;	// 0x190
		cocos2d::CCArray* m_pArray2;	// 0x194
		cocos2d::CCArray* m_pArray3;	// 0x198
		TableViewDelegate* m_pDelegate;	// 0x19c
		TableViewDataSource* m_pDataSource;	// 0x1a0
		PAD(16)
		float m_fTouchLastY;	// 0x1ac
		PAD(4)
	public:
		TableView(cocos2d::CCRect rect) : CCScrollLayerExt(rect) {
			reinterpret_cast<TableView*(__thiscall*)(TableView*, cocos2d::CCRect)>(
				base + 0x30fb0
			)(this, rect);
		}

		void reloadData() {
			reinterpret_cast<void(__thiscall*)(TableView*)>(
				base + 0x317e0
			)(this);
		}

		static TableView* create(TableViewDelegate* delegate, TableViewDataSource* dataSource, cocos2d::CCRect rect) {
			auto pRet = reinterpret_cast<TableView*(__fastcall*)(TableViewDelegate*, TableViewDataSource*, cocos2d::CCRect)>(
				base + 0x30ed0
			)(delegate, dataSource, rect);

			__asm add esp, 0x10

			return pRet;
		}
	};

	class TableViewCell : public cocos2d::CCLayer {
	public:
		bool m_bUnknown;	// 0x11c
		PAD(3)
		TableView* m_pTableView; 	// 0x120
		CCIndexPath m_iIndexPath;	// 0x124
		std::string m_sUnknownString;	// 0x14c
		PAD(4)
		float m_fWidth;		// 0x168
		float m_fHeight;	// 0x16c
		cocos2d::CCLayerColor* m_pBGLayer;	// 0x170
		cocos2d::CCLayer* m_pLayer;	// 0x174
		PAD(4)

		TableViewCell(const char* name, float height, cocos2d::ccColor4B color) {
			__asm {
				movss xmm2, height
				movss xmm3, color
			}
			reinterpret_cast<void(__thiscall*)(TableViewCell*, const char*)>(
				base + 0x32E70
				)(this, name);
		}

		TableViewCell(const char* name, float width, float height) {
			__asm {
				movss xmm2, width
				movss xmm3, height
			}
			reinterpret_cast<void(__thiscall*)(TableViewCell*, const char*)>(
				base + 0x32E70
			)(this, name);
		}

		static TableViewCell* create(const char* name, float width, float height) {
			auto pRet = new TableViewCell(name, width, height);

			if (pRet) {
				pRet->autorelease();
				return pRet;
			}

			CC_SAFE_DELETE(pRet);
			return nullptr;
		}
	};

	class TableViewDelegate {
	public:
		virtual void willTweenToIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void didEndTweenToIndexPath(CCIndexPath&, TableView*) {}
		virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual float cellHeightForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
		virtual void didSelectRowAtIndexPath(CCIndexPath&, TableView*) = 0;
	};

	class TableViewDataSource {
	public:
		virtual unsigned int numberOfRowsInSection(unsigned int, TableView*) = 0;
		virtual unsigned int numberOfSectionsInTableView(TableView*) { return 1; }
		virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView*, TableViewCellEditingStyle, CCIndexPath&) {}
		virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
	};

	class StatsCell : public TableViewCell {
    public:
        void updateBGColor(unsigned int index) {
            reinterpret_cast<void(__thiscall*)(StatsCell*, unsigned int)>(
                base + 0x59cf0
            )(this, index);
        }
    };

	class GJScoreCell : public TableViewCell {
    public:
    	//0x62380 onViewProfile
    	//0x624A0 FLAlert_Clicked
        void loadFromScore(GJUserScore* score) {
            reinterpret_cast<void(__thiscall*)(GJScoreCell*, GJUserScore*)>(
                base + 0x61440
            )(this, score);
        }
        void updateBGColor(unsigned int index) {
            reinterpret_cast<void(__thiscall*)(TableViewCell*, unsigned int)>(
                base + 0x5C6B0
            )(this, index);
        }
    };

    class LevelCell : public TableViewCell {
    public:
        gd::GJGameLevel* level;

        void loadFromLevel(GJGameLevel* level) {
            reinterpret_cast<void(__thiscall*)(LevelCell*, GJGameLevel*)>(
                base + 0x59FD0
            )(this, level);
        }
        void updateBGColor(unsigned int index) {
            reinterpret_cast<void(__thiscall*)(TableViewCell*, unsigned int)>(
                base + 0x5C6B0
            )(this, index);
        }
    };
}

#endif