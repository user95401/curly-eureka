/* #ifndef __CCMENUITEMSPRITEEXTRA_HPP__
#define __CCMENUITEMSPRITEEXTRA_HPP__

typedef enum
{
    MENU_ANIM_TYPE_SCALE = 0,
    MENU_ANIM_TYPE_MOVE = 1,
} MenuAnimationType;

namespace gd {
    class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
    public://cocos2d::
        CCMenuItemSpriteExtra() {
            mScale = 0.0f;
            mSelectedScale = 1.0f;
            mUseAnimation = false;
            mDarken = false;
            mUnknownSFXValue = 1.0f;
            mSelectSound = "";
            mHoverSound = "";
            mDarkenAmount = 0.78431f;
            mOffsetPositionSelected = cocos2d::CCPoint();
            mSelectDuration = 0.3f;
            mUnselectDuration = 0.4f;
            mAnimationType = MENU_ANIM_TYPE_SCALE;
            mOffsetPosition = cocos2d::CCPoint();
        };
        ~CCMenuItemSpriteExtra() override;

        void selected() {
            if (!this->isEnabled())
                return;

            CCMenuItemSprite::selected();

            if (!mHoverSound.empty())
            {
                // TODO: Missing GameSoundManager
                //GameSoundManager* pSoundManager = GameSoundManager::sharedManager();
                //pSoundManager->playEffect(this->mHoverSound, 1.0f, 0.0f, this->mUnknownSFXValue);
            }

            if (mDarken)
            {
                unsigned char color = this->mDarkenAmount * 255.0f;
                cocos2d::CCSprite* sprite = (cocos2d::CCSprite*)this->getNormalImage();
                sprite->setColor({ color, color, color });
            }

            if (mUseAnimation)
            {
                switch (mAnimationType)
                {
                case MENU_ANIM_TYPE_MOVE:
                {
                    cocos2d::CCNode* node = this->getNormalImage();
                    node->stopActionByTag(0);
                    cocos2d::CCMoveTo* moveTo = cocos2d::CCMoveTo::create(mSelectDuration, mOffsetPosition + mOffsetPositionSelected);
                    cocos2d::CCEaseInOut* ease = cocos2d::CCEaseInOut::create(moveTo, 1.5f);
                    ease->setTag(0);
                    node->runAction(ease);
                    break;
                }
                case MENU_ANIM_TYPE_SCALE:
                {
                    this->stopActionByTag(0);
                    cocos2d::CCScaleTo* scaleTo = cocos2d::CCScaleTo::create(mSelectDuration, mScale * mSelectedScale);
                    cocos2d::CCEaseBounceOut* ease = cocos2d::CCEaseBounceOut::create(scaleTo);
                    ease->setTag(0);
                    this->runAction(ease);
                    break;
                }
                }
            }
        };
        void activate() {
            if (!this->isEnabled())
                return;

            this->stopAllActions();
            if (this->mAnimationType == MENU_ANIM_TYPE_SCALE)
                this->setScale(mScale);

            if (!this->mSelectSound.empty())
            {
                // TODO: Missing GameSoundManager
                //GameSoundManager* pSoundManager = GameSoundManager::sharedManager();
                //pSoundManager->playEffect(this->mSelectSound, 1.0f, 0.0f, this->mUnknownSFXValue);
            }

            CCMenuItem::activate();
        };
        void unselected() {
            if (!this->isEnabled())
                return;

            CCMenuItemSprite::unselected();

            if (mDarken)
            {
                cocos2d::CCSprite* sprite = (cocos2d::CCSprite*)this->getNormalImage();
                sprite->setColor(cocos2d::ccWHITE);
            }

            if (mUseAnimation)
            {
                switch (mAnimationType)
                {
                case MENU_ANIM_TYPE_MOVE:
                {
                    cocos2d::CCNode* node = this->getNormalImage();
                    node->stopActionByTag(0);
                    cocos2d::CCMoveTo* moveTo = cocos2d::CCMoveTo::create(mUnselectDuration, mOffsetPosition);
                    cocos2d::CCEaseInOut* ease = cocos2d::CCEaseInOut::create(moveTo, 2.0f);
                    ease->setTag(0);
                    node->runAction(ease);
                    break;
                }
                case MENU_ANIM_TYPE_SCALE:
                {
                    this->stopActionByTag(0);
                    cocos2d::CCScaleTo* scaleTo = cocos2d::CCScaleTo::create(mUnselectDuration, mScale);
                    cocos2d::CCEaseBounceOut* ease = cocos2d::CCEaseBounceOut::create(scaleTo);
                    ease->setTag(0);
                    this->runAction(ease);
                    break;
                }
                }
            }
        };
        void useAnimationType(MenuAnimationType type) {
            this->mOffsetPosition = this->getNormalImage()->getPosition();
            this->mAnimationType = type;
        };
        void setSizeMult(float size) {
            cocos2d::CCNode* normalImage = this->getNormalImage();
            if (!normalImage)
                return;

            cocos2d::CCSize oldSize = this->getContentSize();
            cocos2d::CCSize imgSize = normalImage->getContentSize();

            float sizeX = imgSize.width * normalImage->getScaleX() * size;
            float sizeY = imgSize.height * normalImage->getScaleY() * size;

            cocos2d::CCSize newSize(sizeX, sizeY);

            this->setContentSize(newSize);

            cocos2d::CCSize sz(newSize.width - oldSize.width, newSize.height - oldSize.height);
            normalImage->setPosition(normalImage->getPosition() + cocos2d::CCPoint(sz.width * 0.5f, sz.height * 0.5f));
        };

        void setSelectedScale(float scale) { mSelectedScale = scale; }

        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual bool init(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector) {
            if (!CCMenuItemSprite::initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector))
                return false;

            this->mScale = 1.0f;
            normalSprite->setAnchorPoint(cocos2d::CCPoint(0.5f, 0.5f));

            cocos2d::CCSize size = normalSprite->getContentSize();
            this->setContentSize(cocos2d::CCSize(size.width * normalSprite->getScaleX(), size.height));

            normalSprite->setPosition(normalSprite->getParent()->convertToNodeSpace(cocos2d::CCPoint(0.0f, 0.0f)));

            //this->mDarken = true;
            this->mUseAnimation = true;
            this->mSelectedScale = 1.26f;

            return true;
        };

        static CCMenuItemSpriteExtra* create(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector) {
            CCMenuItemSpriteExtra* pRet = new CCMenuItemSpriteExtra();
            if (pRet && pRet->init(normalSprite, selectedSprite, target, selector))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        };

    protected:
        MenuAnimationType mAnimationType;
        cocos2d::CCPoint mOffsetPosition;
        float mScale;
        std::string mSelectSound;
        std::string mHoverSound;
        float mUnknownSFXValue;
        float mDarkenAmount;
        float mSelectDuration;
        float mUnselectDuration;
        cocos2d::CCPoint mOffsetPositionSelected;
        bool mUseAnimation;
        bool mDarken;
        float mSelectedScale;
    };
}

#endif */