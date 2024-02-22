#ifndef __GD_H__
#define __GD_H__

#include <cocos2d.h>
#include <cocos-ext.h>
#include <patterns.hpp>

inline auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
inline auto libcocos2d = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));

inline bool gdh_init() {
	static_assert(sizeof(std::string) == 24,
		"\n[GD.H] std::string is not 24 bytes\n" \
		"[GD.H] Any classes containing member strings or using strings in functions will break!\n" \
		"[GD.H] this is caused by building in Debug mode, to fix switch to Release\n");
	return base;
}

//hi
#define TodoReturn void
#define cast(type, call, value_types, values, addr) reinterpret_cast<type(call)value_types>(addr)values;
#define addrViaPattern(tar) \
auto addr = patterns::find_pattern(tar, ""); \
if (!addr) cocos2d::CCMessageBox("find_pattern failed", __FUNCTION__); \

//predcl
#if 1
class PlayerButtonCommand;
class FMODSound;
class AdvancedFollowInstance;
class SFXTriggerInstance;
class EventTriggerInstance;
class SongChannelState;
class ChanceObject;
class GameObjectPhysics;
class DynamicObjectAction;
class GJTransformState;
class CAState;
class GJPointDouble;
class GJDropDownLayer;
class GJAccountDelegate;
class FLAlertLayerProtocol;
class AccountHelpLayer;
class GJAccountBackupDelegate;
class GJAccountSyncDelegate;
class AccountLayer;
class FLAlertLayer;
class TextInputDelegate;
class GJAccountLoginDelegate;
class AccountLoginLayer;
class GJAccountRegisterDelegate;
class AccountRegisterLayer;
class AchievementBar;
class CCIndexPath;
class TableViewCell;
class AchievementCell;
class AchievementManager;
class AchievementNotifier;
class AchievementsLayer;
class AdToolbox;
class CCSpritePlus;
class GameObject;
class EnhancedGameObject;
class EffectGameObject;
class AdvancedFollowTriggerObject;
class AdvancedFollowEditObject;
class AdvFollowSetup;
class AnimatedSpriteDelegate;
class SpritePartDelegate;
class AnimatedGameObject;
class CCAnimatedSprite;
class AnimatedShopKeeper;
class AppDelegate;
class ArtistCell;
class ArtTriggerGameObject;
class AudioEffectsLayer;
class AudioLineGuideGameObject;
class BitmapFontCache;
class BonusDropdown;
class BoomListLayer;
class TableViewDelegate;
class TableViewDataSource;
class BoomListView;
class BoomScrollLayer;
class BoomScrollLayerDelegate;
class BrowseSmartTemplateLayer;
class BrowseSmartKeyLayer;
class ButtonPage;
class ButtonSprite;
class CameraTriggerGameObject;
class CCAlertCircle;
class CCAnimateFrameCache;
class CCBlockLayer;
class CCCircleWave;
class CCCircleAlert;
class CCCircleWaveDelegate;
class CCContentLayer;
class CCCountdown;
class CCCounterLabel;
class CCExtenderNode;
class CCLightFlash;
class CCLightStrip;
class CCMenuItemSpriteExtra;
class CCMenuItemToggler;
class CCMoveCNode;
class CCNodeContainer;
class CCPartAnimSprite;
class CCScrollLayerExt;
class CCScrollLayerExtDelegate;
class CCSpriteCOpacity;
class CCSpriteWithHue;
class CCSpriteGrayscale;
class CCSpritePart;
class CCTextInputNode;
class CCURLObject;
class ChallengeNode;
class GJChallengeDelegate;
class CurrencyRewardDelegate;
class ChallengesPage;
class ChanceTriggerGameObject;
class CharacterColorDelegate;
class CharacterColorPage;
class CheckpointGameObject;
class CheckpointObject;
class CollisionBlockPopup;
class ColorAction;
class ColorAction2;
class ColorActionSprite;
class ColorChannelSprite;
class ColorSelectDelegate;
class ColorSelectLiveOverlay;
class ConfigureValuePopupDelegate;
class SliderDelegate;
class SetupTriggerPopup;
class GJSpecialColorSelectDelegate;
class ColorSelectPopup;
class ColorSetupDelegate;
class LikeItemDelegate;
class CommentCell;
class CommentUploadDelegate;
class CommunityCreditNode;
class CommunityCreditsPage;
class ConfigureHSVWidget;
class ConfigureValuePopup;
class CountTriggerAction;
class CountTriggerGameObject;
class CreateGuidelinesLayer;
class CreateMenuItem;
class CreateParticlePopup;
class DialogDelegate;
class CreatorLayer;
class CurrencyRewardLayer;
class CurrencySprite;
class HSVWidgetDelegate;
class CustomizeObjectLayer;
class CustomizeObjectSettingsPopup;
class CustomListView;
class CustomSongDelegate;
class CustomSongCell;
class CustomMusicCell;
class CustomSFXDelegate;
class CustomSFXCell;
class MusicDownloadDelegate;
class CustomSFXWidget;
class GJDropDownLayerDelegate;
class MusicBrowserDelegate;
class CustomSongLayer;
class CustomSongLayerDelegate;
class GJAssetDownloadAction;
class CustomSongWidget;
class DailyLevelNode;
class GJDailyLevelDelegate;
class LevelDownloadDelegate;
class DailyLevelPage;
class RingObject;
class DashRingObject;
class DemonFilterDelegate;
class DemonFilterSelectLayer;
class TextAreaDelegate;
class DialogLayer;
class DialogObject;
class DownloadMessageDelegate;
class DrawGridLayer;
class DungeonBarsSprite;
class DynamicBitset;
class DynamicScrollDelegate;
class EditButtonBar;
class EditGameObjectPopup;
class UploadActionDelegate;
class UploadPopupDelegate;
class SetIDPopupDelegate;
class EditLevelLayer;
class GJOptionsLayer;
class EditorOptionsLayer;
class EditorPauseLayer;
class GJRotationControlDelegate;
class GJScaleControlDelegate;
class GJTransformControlDelegate;
class EditorUI;
class EditTriggersPopup;
class EffectManagerState;
class EndLevelLayer;
class EndPortalObject;
class EndTriggerGameObject;
class EnhancedTriggerObject;
class EnterEffectInstance;
class EnterEffectObject;
class EventLinkTrigger;
class ExplodeItemNode;
class ExplodeItemSprite;
class ExtendedLayer;
class FileOperation;
class GManager;
class FileSaveManager;
class FindBPMLayer;
class SetIDPopup;
class FindObjectPopup;
class FMODAudioEngine;
class FMODAudioState;
class FMODLevelVisualizer;
class GameRateDelegate;
class RewardedVideoDelegate;
class FollowRewardPage;
class FontObject;
class ForceBlockGameObject;
class FriendRequestDelegate;
class FRequestProfilePage;
class FriendRequestPopup;
class UserListDelegate;
class FriendsProfilePage;
class GameCell;
class GameEffectsManager;
class GameLevelManager;
class GameLevelOptionsLayer;
class UIButtonConfig;
class GameManager;
class GameObjectCopy;
class GameObjectEditorState;
class GameOptionsLayer;
class GameOptionsTrigger;
class GameStatsManager;
class GameToolbox;
class LevelManagerDelegate;
class GauntletLayer;
class GauntletNode;
class GauntletSelectLayer;
class GauntletSprite;
class GhostTrailEffect;
class GJAccountManager;
class GJAccountSettingsDelegate;
class GJAccountSettingsLayer;
class GJActionManager;
class GJValueTween;
class GJGameState;
class TriggerEffectDelegate;
class GJBaseGameLayer;
class GJBigSprite;
class GJBigSpriteNode;
class GJChallengeItem;
class GJChestSprite;
class GJColorSetupLayer;
class GJComment;
class GJCommentListLayer;
class GJDifficultySprite;
class GJEffectManager;
class GJGroundLayer;
class GJFlyGroundLayer;
class GJFollowCommandLayer;
class GJFriendRequest;
class GJGameLevel;
class GJGameLoadingLayer;
class ListButtonBarDelegate;
class GJGarageLayer;
class GJGradientLayer;
class GJHttpResult;
class GJItemIcon;
class GJLevelList;
class GJLevelScoreCell;
class GJListLayer;
class GJLocalLevelScoreCell;
class GJLocalScore;
class GJMapObject;
class GJMapPack;
class GJMessageCell;
class GJMessagePopup;
class GJMGLayer;
class GJMoreGamesLayer;
class GJMPDelegate;
class GJMultiplayerManager;
class ObjectDecoderDelegate;
class GJObjectDecoder;
class GJPurchaseDelegate;
class GJPathPage;
class GJPathRewardPopup;
class GJPathsLayer;
class GJPathSprite;
class GJPFollowCommandLayer;
class GJPromoPopup;
class GJRequestCell;
class GJRewardDelegate;
class GJRewardItem;
class GJRewardObject;
class GJRobotSprite;
class GJRotateCommandLayer;
class GJRotationControl;
class GJScaleControl;
class GJScoreCell;
class GJSearchObject;
class GJShaderState;
class GJShopLayer;
class GJSmartBlockPreview;
class GJSmartBlockPreviewSprite;
class GJSmartPrefab;
class GJSmartTemplate;
class TableViewCellDelegate;
class GJSongBrowser;
class GJSpecialColorSelect;
class GJSpiderSprite;
class GJSpriteColor;
class GJStoreItem;
class GJTransformControl;
class GJUINode;
class GJUnlockableItem;
class GJUserCell;
class GJUserMessage;
class GJUserScore;
class GJWorldNode;
class UploadMessageDelegate;
class GJWriteMessagePopup;
class GooglePlayDelegate;
class GooglePlayManager;
class GradientTriggerObject;
class GraphicsReloadLayer;
class GravityEffectSprite;
class GroupCommandObject2;
class HardStreak;
class HSVLiveOverlay;
class HSVWidgetPopup;
class InfoAlertButton;
class LevelCommentDelegate;
class InfoLayer;
class InheritanceNode;
class ItemInfoPopup;
class ItemTriggerGameObject;
class KeybindingsLayer;
class KeybindingsManager;
class KeyframeAnimTriggerObject;
class KeyframeGameObject;
class KeyframeObject;
class LabelGameObject;
class LeaderboardManagerDelegate;
class LeaderboardsLayer;
class LevelAreaInnerLayer;
class LevelAreaLayer;
class SetTextPopupDelegate;
class ShareCommentDelegate;
class LevelBrowserLayer;
class LevelCell;
class LevelDeleteDelegate;
class LevelSettingsDelegate;
class LevelEditorLayer;
class LevelFeatureLayer;
class LevelUpdateDelegate;
class RateLevelDelegate;
class NumberInputDelegate;
class LevelInfoLayer;
class LevelLeaderboard;
class LevelListCell;
class LevelListDeleteDelegate;
class SelectListIconDelegate;
class LevelListLayer;
class LevelOptionsLayer;
class LevelOptionsLayer2;
class LevelPage;
class LevelSearchLayer;
class LevelSelectLayer;
class SelectArtDelegate;
class SelectSettingDelegate;
class LevelSettingsLayer;
class LevelSettingsObject;
class LevelTools;
class LevelUploadDelegate;
class LikeItemLayer;
class ListButtonBar;
class ListButtonPage;
class ListCell;
class ListUploadDelegate;
class LoadingCircle;
class LoadingCircleSprite;
class LoadingLayer;
class LocalLevelManager;
class MapPackCell;
class MapSelectLayer;
class MenuGameLayer;
class MenuLayer;
class MessageListDelegate;
class MessagesProfilePage;
class MoreOptionsLayer;
class MoreSearchLayer;
class MoreVideoOptionsLayer;
class MPLobbyLayer;
class MultilineBitmapFont;
class MultiplayerLayer;
class MultiTriggerPopup;
class MusicArtistObject;
class MusicBrowser;
class MusicDelegateHandler;
class PlatformDownloadDelegate;
class MusicDownloadManager;
class OptionsObjectDelegate;
class MusicSearchResult;
class NewgroundsInfoLayer;
class NodePoint;
class NumberInputLayer;
class OBB2D;
class ObjectControlGameObject;
class ObjectDecoder;
class ObjectManager;
class ObjectToolbox;
class OnlineListDelegate;
class OpacityEffectAction;
class OptionsCell;
class OptionsLayer;
class OptionsObject;
class OptionsScrollLayer;
class ParentalOptionsLayer;
class ParticleGameObject;
class ParticlePreviewLayer;
class PauseLayer;
class PlatformToolbox;
class PlayerCheckpoint;
class PlayerControlGameObject;
class PlayerFireBoostSprite;
class PlayerObject;
class PlayLayer;
class PointNode;
class PriceLabel;
class UserInfoDelegate;
class ProfilePage;
class PromoInterstitial;
class PulseEffectAction;
class PurchaseItemPopup;
class RandTriggerGameObject;
class RateDemonLayer;
class RateLevelLayer;
class RateStarsLayer;
class RetryLevelLayer;
class RewardsPage;
class RewardUnlockLayer;
class RotateGameplayGameObject;
class ScrollingLayer;
class SearchButton;
class SetTextPopup;
class SearchSFXPopup;
class SecretLayer;
class SecretLayer2;
class SecretLayer3;
class SecretLayer4;
class SecretNumberLayer;
class SecretRewardsLayer;
class SelectArtLayer;
class SelectEventLayer;
class SelectFontLayer;
class SelectListIconLayer;
class SelectPremadeDelegate;
class SelectPremadeLayer;
class SelectSettingLayer;
class SelectSFXSortDelegate;
class SelectSFXSortLayer;
class SequenceTriggerGameObject;
class SetColorIDPopup;
class SetFolderPopup;
class SetGroupIDLayer;
class SetItemIDLayer;
class SetLevelOrderPopup;
class SetTargetIDLayer;
class SetupAdvFollowEditPhysicsPopup;
class SetupAdvFollowPopup;
class SetupAdvFollowRetargetPopup;
class SetupAnimationPopup;
class SetupAnimSettingsPopup;
class SetupAreaMoveTriggerPopup;
class SetupAreaTintTriggerPopup;
class SetupAreaAnimTriggerPopup;
class SetupAreaFadeTriggerPopup;
class SetupAreaRotateTriggerPopup;
class SetupAreaTransformTriggerPopup;
class SetupAreaTriggerPopup;
class SetupArtSwitchPopup;
class SetupAudioLineGuidePopup;
class SetupAudioTriggerPopup;
class SetupBGSpeedTrigger;
class SetupCameraEdgePopup;
class SetupCameraGuidePopup;
class SetupCameraModePopup;
class SetupCameraOffsetTrigger;
class SetupCameraRotatePopup;
class SetupCameraRotatePopup2;
class SetupCheckpointPopup;
class SetupCoinLayer;
class SetupInstantCollisionTriggerPopup;
class SetupCollisionStateTriggerPopup;
class SetupCollisionTriggerPopup;
class SetupCountTriggerPopup;
class SetupDashRingPopup;
class SetupEndPopup;
class SetupEnterEffectPopup;
class SetupEnterTriggerPopup;
class SetupEventLinkPopup;
class SetupForceBlockPopup;
class SetupGameplayOffsetPopup;
class SetupGradientPopup;
class SetupGravityModPopup;
class SetupGravityTriggerPopup;
class SetupInstantCountPopup;
class SetupInteractObjectPopup;
class SetupItemCompareTriggerPopup;
class SetupItemEditTriggerPopup;
class SetupKeyframeAnimPopup;
class SetupKeyframePopup;
class SetupMGTrigger;
class SetupMoveCommandPopup;
class SetupObjectControlPopup;
class SetupObjectOptions2Popup;
class SetupObjectOptionsPopup;
class SetupObjectTogglePopup;
class SetupOpacityPopup;
class SetupOptionsTriggerPopup;
class SetupPersistentItemTriggerPopup;
class SetupPickupTriggerPopup;
class SetupPlatformerEndPopup;
class SetupPlayerControlPopup;
class SetupPortalPopup;
class SetupPulsePopup;
class SetupRandAdvTriggerPopup;
class SetupRandTriggerPopup;
class SetupResetTriggerPopup;
class SetupReverbPopup;
class SetupRotateCommandPopup;
class SetupRotateGameplayPopup;
class SetupRotatePopup;
class SetupSequenceTriggerPopup;
class SetupSFXEditPopup;
class SFXBrowserDelegate;
class SetupSFXPopup;
class SetupShaderEffectPopup;
class SetupShakePopup;
class SetupSmartBlockLayer;
class SetupSmartTemplateLayer;
class SongPlaybackDelegate;
class SetupSongTriggerPopup;
class SetupSpawnParticlePopup;
class SetupSpawnPopup;
class SetupStaticCameraPopup;
class SetupStopTriggerPopup;
class SetupTeleportPopup;
class SetupTimerControlTriggerPopup;
class SetupTimerEventTriggerPopup;
class SetupTimerTriggerPopup;
class SetupTimeWarpPopup;
class SetupTouchTogglePopup;
class SetupTransformPopup;
class SetupZoomTriggerPopup;
class SFXBrowser;
class SFXInfoObject;
class SFXFolderObject;
class SFXSearchResult;
class SFXTriggerGameObject;
class ShaderGameObject;
class ShaderLayer;
class ShardsPage;
class ShareCommentLayer;
class ShareLevelLayer;
class ShareLevelSettingsLayer;
class ShareListLayer;
class SimpleObject;
class SimplePlayer;
class SlideInLayer;
class Slider;
class SliderThumb;
class SliderTouchLogic;
class SmartGameObject;
class SmartTemplateCell;
class SongCell;
class SongInfoLayer;
class SongInfoObject;
class SongObject;
class SongOptionsLayer;
class SongSelectNode;
class SongsLayer;
class SongTriggerGameObject;
class SpawnParticleGameObject;
class SpawnTriggerAction;
class SpawnTriggerGameObject;
class SpecialAnimGameObject;
class SpriteAnimationManager;
class SpriteDescription;
class StartPosObject;
class StatsCell;
class StatsLayer;
class StatsObject;
class SupportLayer;
class TableView;
class TeleportPortalObject;
class TextAlertPopup;
class TextArea;
class TextGameObject;
class TextStyleSection;
class TimerTriggerGameObject;
class TopArtistsLayer;
class TOSPopup;
class TransformTriggerGameObject;
class TriggerControlGameObject;
class TutorialLayer;
class TutorialPopup;
class UILayer;
class UIObjectSettingsPopup;
class UIOptionsLayer;
class UISaveLoadLayer;
class UISettingsGameObject;
class UndoObject;
class UpdateAccountSettingsPopup;
class UploadActionPopup;
class UploadListPopup;
class UploadPopup;
class URLCell;
class URLViewLayer;
class VideoOptionsLayer;
class WorldLevelPage;
class WorldSelectLayer;
#endif // 1

// https://github.com/geode-sdk/geode/blob/main/loader/include/Geode/utils/SeedValue.hpp
#if 1
struct BaseSeedValue
{
	BaseSeedValue() = default;
	BaseSeedValue(BaseSeedValue const& other) = default;
	BaseSeedValue(BaseSeedValue&& other) = default;
	BaseSeedValue& operator=(BaseSeedValue const& other) = default;
	BaseSeedValue& operator=(BaseSeedValue&& other) = default;
};
struct SeedValueRSV : public BaseSeedValue
{
	int m_value_rand;
	int m_value_seed;
	int m_value;

	int value() const { return m_value; }
};
struct SeedValueVSR : public BaseSeedValue
{
	int m_value;
	int m_value_seed;
	int m_value_rand;

	int value() const { return m_value; }
};
struct SeedValueRS : public BaseSeedValue
{
	int m_value_rand;
	int m_value_seed;

	int value() const { return m_value_rand - m_value_seed; }
};
#endif // 1

//levels stuff
#if 1
enum GJLevelType {
	kGJLevelTypeLocal = 1,
	kGJLevelTypeEditor = 2,
	kGJLevelTypeSaved = 3
};
enum GJDifficulty {
	kGJDifficultyAuto = 0,
	kGJDifficultyEasy = 1,
	kGJDifficultyNormal = 2,
	kGJDifficultyHard = 3,
	kGJDifficultyHarder = 4,
	kGJDifficultyInsane = 5,
	kGJDifficultyDemon = 6,
	kGJDifficultyDemonEasy = 7,
	kGJDifficultyDemonMedium = 8,
	kGJDifficultyDemonInsane = 9,
	kGJDifficultyDemonExtreme = 10
};
class GJGameLevel /* 0x3bc */ : public cocos2d::CCNode {
public:

	cocos2d::CCDictionary* m_pLastBuildSave;   // 0xec
	SeedValueRSV m_nLevelID;      // 0xf8
	std::string m_sLevelName;       // 0xfc
	std::string m_sLevelDesc;       // 0x114
	std::string m_sLevelString;     // 0x12c
	std::string m_sCreatorName;     // 0x144
	std::string m_sRecordString;    // 0x15c
	std::string m_sUploadDate; // 0x174
	std::string m_sUpdateDate; // 0x18c

	std::string m_unkString1;
	std::string m_unkString2;

	cocos2d::CCPoint m_unkPoint;
	SeedValueRSV m_userID;
	SeedValueRSV m_accountID;
	GJDifficulty m_difficulty;
	int m_audioTrack;
	int m_songID;
	int m_levelRev;
	bool m_unlisted;
	bool m_friendsOnly;
	SeedValueRSV m_objectCount;
	int m_levelIndex;
	int m_ratings;
	int m_ratingsSum;
	int m_downloads;
	bool m_isEditable;
	bool m_gauntletLevel;
	bool m_gauntletLevel2;
	int m_workingTime;
	int m_workingTime2;
	bool m_lowDetailMode;
	bool m_lowDetailModeToggled;
	bool m_selected;
	bool m_localOrSaved;
	bool m_disableShake;
	SeedValueRS m_isVerified;
	bool m_isVerifiedRaw;
	bool m_isUploaded;
	bool m_hasBeenModified;
	int m_levelVersion;
	int m_gameVersion;

	SeedValueRSV m_attempts;
	SeedValueRSV m_jumps;
	SeedValueRSV m_clicks;
	SeedValueRSV m_attemptTime;
	int m_chk;
	bool m_isChkValid;
	bool m_isCompletionLegitimate;
	SeedValueVSR m_normalPercent;
	SeedValueRSV m_orbCompletion;
	SeedValueRSV m_newNormalPercent2;
	int m_practicePercent;
	int m_likes;
	int m_dislikes;
	int m_levelLength;
	int m_featured;
	int m_isEpic;
	bool m_levelFavorited;
	int m_levelFolder;
	SeedValueRSV m_dailyID;
	SeedValueRSV m_demon;
	int m_demonDifficulty;
	SeedValueRSV m_stars;
	bool m_autoLevel;
	int m_coins;
	SeedValueRSV m_coinsVerified;
	SeedValueRS m_password;
	SeedValueRSV m_originalLevel;
	bool m_twoPlayerMode;
	int m_failedPasswordAttempts;
	SeedValueRSV m_firstCoinVerified;
	SeedValueRSV m_secondCoinVerified;
	SeedValueRSV m_thirdCoinVerified;
	int m_starsRequested;
	bool m_showedSongWarning;
	int m_starRatings;
	int m_starRatingsSum;
	int m_maxStarRatings;
	int m_minStarRatings;
	int m_demonVotes;
	int m_rateStars;
	int m_rateFeature;
	std::string m_rateUser;
	bool m_dontSave;
	bool m_levelNotDownloaded;
	int m_requiredCoins;
	bool m_isUnlocked;
	cocos2d::CCPoint m_lastCameraPos;
	float m_fastEditorZoom;
	int m_lastBuildTab;
	int m_lastBuildPage;
	int m_lastBuildGroupID;
	GJLevelType m_levelType;
	int m_M_ID;
	std::string m_tempName;
	std::string m_capacityString;
	bool m_highObjectsEnabled;
	bool m_unlimitedObjectsEnabled;
	std::string m_personalBests;
	int m_timestamp;
	int m_unkInt;
	std::string m_songIDs;
	std::string m_sfxIDs;
	int m_54;
	int m_bestTime;
	int m_bestPoints;
	int m_k111;
	std::string m_unkString3;
	std::string m_unkString4;
};
#endif

//menu_nodes
#if 1
enum MenuAnimationType {
	Scale = 0,
	Move = 1,
};
class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
public:
	float m_scaleMultiplier;
	float m_baseScale;
	bool m_animationEnabled;
	bool m_colorEnabled;
	float m_unknown1;
	std::string m_unknown2;
	std::string m_unknown3;
	float m_colorDip;
	cocos2d::CCPoint m_destPosition;
	cocos2d::CCPoint m_offset;
	MenuAnimationType m_animationType;
	cocos2d::CCPoint m_startPosition;
	int m_unknown4;
	//unno.. 0x25830?
	static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) {
		//cast it
        addrViaPattern(
            "? ? ? ? ? ? ? ? ? ? 64 a1 ? ? ? ? 50 83 ec ? 56 57 a1 ? ? ? ? 33 c5 50 8d 45 ? 64 a3 ? ? ? ? 8b f9 68 ? ? ? ? ff 15 ? ? ? ? 83 c4 ? 89 45 ? c7 45 ? ? ? ? ? 85 c0 74 ? 8b c8 e8 ? ? ? ? 8b f0 eb ? 33 f6 c7 45 ? ? ? ? ? 85 f6 74 ? ff 75 ? 8b ce ff 75 ? 6a ? 6a ? 57 ff 15 ? ? ? ? 84 c0 74 ? 57 8b ce e8 ? ? ? ? 84 c0 74 ? 8b ce ff 15 ? ? ? ? 8b c6 8b 4d ? 64 89 0d ? ? ? ? 59 5f 5e 8b e5 5d c3 8b 06 8b ce 6a ? ff 50 ? 33 c0"
        );
        auto ret = cast(
            CCMenuItemSpriteExtra*,
            __thiscall*,
            (cocos2d::CCNode * sprite, cocos2d::CCObject * target, cocos2d::SEL_MenuHandler callback),
            (                  sprite,                     target,                          callback),
            addr
            );
		//fix stack before returning
		__asm add esp, 0x8
		return ret;//create(sprite, sprite, target, callback);
	};
	//0x258f0
	bool init(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCObject* p2, cocos2d::SEL_MenuHandler p3) {
		//cast it
	};
	//unno
	inline void setSizeMult(float mult) {
		m_scaleMultiplier = mult;
	}
	//unno
	void useAnimationType(MenuAnimationType p0) {
		m_animationType = p0;
	};
	//0x259d0 not implemented
	virtual void activate() {
		//cast it
	};
	//0x25aa0 not implemented
	virtual void selected() {
		//cast it
	};
	//0x25c80 not implemented
	virtual void unselected() {
		//cast it
	};
};
class CCTextInputNode;
class TextInputDelegate {
public:
	virtual void textChanged(CCTextInputNode* p0) {};
	virtual void textInputOpened(CCTextInputNode* p0) {};
	virtual void textInputClosed(CCTextInputNode* p0) {};
	virtual void textInputShouldOffset(CCTextInputNode* p0, float p1) {};
	virtual void textInputReturn(CCTextInputNode* p0) {};
	virtual bool allowTextInput(CCTextInputNode* p0) {};
	virtual void enterPressed(CCTextInputNode* p0) {};
};
class CCTextInputNode : public cocos2d::CCLayer, public cocos2d::CCIMEDelegate, public cocos2d::CCTextFieldDelegate {
public:
	//0x2e440
	static CCTextInputNode* create(float p0, float p1, char const* p2, char const* p3, int p4, char const* p5) {
		//cast it
		//auto pattern = "? ? ? ? ? ? ? ? ? ? 64 a1 ? ? ? ? 50 83 ec ? 56 57 a1 ? ? ? ? 33 c5 50 8d 45 ? 64 a3 ? ? ? ? 8b f9 68 ? ? ? ? ff 15 ? ? ? ? 83 c4 ? 89 45 ? c7 45 ? ? ? ? ? 85 c0 74 ? 8b c8 e8 ? ? ? ? 8b f0 eb ? 33 f6 c7 45 ? ? ? ? ? 85 f6 74 ? ff 75 ? 8b ce ff 75 ? 6a ? 6a ? 57 ff 15 ? ? ? ? 84 c0 74 ? 57 8b ce e8 ? ? ? ? 84 c0 74 ? 8b ce ff 15 ? ? ? ? 8b c6 8b 4d ? 64 89 0d ? ? ? ? 59 5f 5e 8b e5 5d c3 8b 06 8b ce 6a ? ff 50 ? 33 c0";
		//auto addr = patterns::find_pattern(pattern, "");
		//if (!addr) cocos2d::CCMessageBox("find_pattern failed", __FUNCTION__);
		auto pRet = reinterpret_cast
			<
			CCTextInputNode * (__thiscall*)
			(float p0, float p1, char const* p2, char const* p3, int p4, char const* p5)
			>
			(base + 0x2e440)
			(p0, p1, p2, p3, p4, p5);
		return pRet;
	};
	//no
	static CCTextInputNode* create(float width, float height, char const* placeholder, char const* fontPath) {};
	//no
	static CCTextInputNode* create(float width, float height, char const* placeholder, int fontSize, char const* fontPath) {};
	//TextInputDelegate* delegate
	void setDelegate(void* delegate) {};
	//no
	void setMaxLabelScale(float v) {};
	//no
	void setMaxLabelWidth(float v) {};
	//no
	void setMaxLabelLength(int v) {};
	//no
	void setLabelPlaceholderScale(float v) {};
	//no
	void setLabelPlaceholderColor(cocos2d::ccColor3B color) {};
	//no
	void setAllowedChars(std::string filter) {};
	//no
	cocos2d::CCLabelBMFont* getPlaceholderLabel() {};
	//0x2e6d0 p0 TextArea
	void addTextArea(CCNode* p0) {};
	//idk rtn
	void forceOffset() {};
	//dk
	std::string getString() {};
	//0x2e500
	bool init(float p0, float p1, char const* p2, char const* p3, int p4, char const* p5) {};
	//0x2ede0 idk rtn
	void refreshLabel() {};
	//dk
	void setLabelNormalColor(cocos2d::ccColor3B color) {};
	//0x2e9a0
	void setString(std::string p0) {};
	//unno idk rtn
	void updateBlinkLabel() {};
	//unno idk rtn
	void updateBlinkLabelToChar(int p0) {};
	//0x2ff50 idk rtn
	void updateCursorPosition(cocos2d::CCPoint p0, cocos2d::CCRect p1) {};
	//0x2e7a0
	void updateDefaultFontValues(std::string p0) {};
	//0x2eac0 idk rtn
	void updateLabel(std::string p0) {};
	//0x2e930
	virtual void visit() {};
	//0x304f0
	virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {};
	//unno
	virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {};
	//unno
	virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {};
	//unno
	virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {};
	//0x306d0
	virtual void registerWithTouchDispatcher() {};
	//0x2f630 idk rtn
	virtual void textChanged() {};
	//0x2f600 idk rtn
	virtual void onClickTrackNode(bool p0) {};
	//0x2f4d0
	virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& p0) {};
	//0x2f5a0
	virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& p0) {};
	//0x2f6b0
	virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* pSender, char const* text, int nLen, cocos2d::enumKeyCodes keyCodes) {};
	//0x2fa30
	virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* p0) {};
	//0x2fd50
	virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* p0) {};
	bool m_numberInput;
	std::string m_caption;
	int m_unknown1;
	bool m_selected;
	bool m_unknown2;
	float m_fontValue1;
	float m_fontValue2;
	bool m_isChatFont;
	std::string m_allowedChars;
	float m_maxLabelWidth;
	float m_maxLabelScale;
	float m_placeholderScale;
	cocos2d::ccColor3B m_placeholderColor;
	cocos2d::ccColor3B m_textColor;
	cocos2d::CCLabelBMFont* m_cursor;
	cocos2d::CCTextFieldTTF* m_textField;
	TextInputDelegate* m_delegate;//TextInputDelegate
	int m_maxLabelLength;
	cocos2d::CCLabelBMFont* m_placeholderLabel;
	bool m_unknown3;
	bool m_usePasswordChar;
	bool m_forceOffset;
	CCNode* m_textArea;//uk
};
#endif

//managers, accounts and scores stuff
#if 1
class GJAccountSyncDelegate {
	virtual void syncAccountFinished() {};
	virtual void syncAccountFailed(void*, int) {};
};
class GJAccountBackupDelegate {
	virtual void backupAccountFinished() {};
	virtual void backupAccountFailed(void*, int) {};
};
class GJAccountDelegate {
	virtual void accountStatusChanged() {};
};
class GJAccountLoginDelegate {
	virtual void loginAccountFinished(int, int) {};
	virtual void loginAccountFailed(void*) {};
};
class GJAccountRegisterDelegate {
	virtual void registerAccountFinished() {};
	virtual void registerAccountFailed(void*) {};
};
class GJAccountSettingsDelegate {
	virtual void updateSettingsFinished() {};
	virtual void updateSettingsFailed() {};
};
class GJAccountManager : cocos2d::CCNode {
public:
	// virtual ~GJAccountManager() {};
	// GJAccountManager() = win 0x18a400;

	//static GJAccountManager* sharedState() = win 0x18a510;
	static GJAccountManager* sharedState() {
		auto pattern = "55 8b ec 6a ? 68 ? ? ? ? 64 a1 ? ? ? ? 50 51 a1 ? ? ? ? 33 c5 50 8d 45 ? 64 a3 ? ? ? ? a1 ? ? ? ? 85 c0 75 ? 68 ? ? ? ? ff 15 ? ? ? ? 83 c4 ? 89 45 ? c7 45 ? ? ? ? ? 85 c0 74 ? 8b c8 e8 ? ? ? ? 8b c8 eb ? 33 c9 c7 45 ? ? ? ? ? 8b 01 89 0d ? ? ? ? ff 50 ? a1 ? ? ? ? 8b 4d ? 64 89 0d ? ? ? ? 59 8b e5 5d c3 cc cc cc cc cc 55 8b ec 6a ? 68 ? ? ? ? 64 a1 ? ? ? ? 50 51 56";
		auto addr = patterns::find_pattern(pattern, "");
		if (!addr) cocos2d::CCMessageBox("find_pattern failed", __FUNCTION__);
		return reinterpret_cast<GJAccountManager*(__stdcall*)()>(addr)();
	}

	virtual bool init() {};

	cocos2d::CCDictionary* m_activeDownloads;
	std::string m_username;
	int m_accountID;
	int m_unkInt1;
	int m_unkInt2;
	std::string m_GJP2;
	GJAccountRegisterDelegate* m_accountRegisterDelegate;
	GJAccountLoginDelegate* m_accountLoginDelegate;
	GJAccountDelegate* m_accountDelegate;
	GJAccountBackupDelegate* m_backupDelegate;
	GJAccountSyncDelegate* m_syncDelegate;
	GJAccountSettingsDelegate* m_accountSettingsDelegate;
	int m_gameManagerSize;
	int m_localLevelsSize;
	std::string m_password;
}; 
enum IconType {
	Cube = 0,
	Ship = 1,
	Ball = 2,
	Ufo = 3,
	Wave = 4,
	Robot = 5,
	Spider = 6,
	Swing = 7,
	Jetpack = 8,
	DeathEffect = 98,
	Special = 99,
	ShipFire = 101,
};
enum UnlockType {
    kUnlockTypeUnknown = 0,
    kUnlockTypeCube = 1,
    kUnlockTypeColor1 = 2,
    kUnlockTypeColor2 = 3,
    kUnlockTypeShip = 4,
    kUnlockTypeBall = 5,
    kUnlockTypeUfo = 6,
    kUnlockTypeWave = 7,
    kUnlockTypeRobot = 8,
    kUnlockTypeSpider = 9,
    kUnlockTypeSpecial = 10,
    kUnlockTypeDeathEffect = 11,
    kUnlockTypeGlow = 12,
};
class GJUserScore : cocos2d::CCNode {
public:
	// virtual ~GJUserScore() {};
	std::string m_userName;
	std::string m_userUDID;
	int m_scoreType;
	int m_userID;
	int m_accountID;
	int m_stars;
	int m_moons;
	int m_diamonds;
	int m_demons;
	int m_playerRank;
	int m_creatorPoints;
	int m_secretCoins;
	int m_userCoins;
	int m_iconID;
	int m_color1;
	int m_color2;
	int m_color3;
	int m_special;
	IconType m_iconType;
	int m_messageState;
	int m_friendStatus;
	int m_commentHistoryStatus;
	std::string m_youtubeURL;
	std::string m_twitterURL;
	std::string m_twitchURL;
	int m_playerCube;
	int m_playerShip;
	int m_playerBall;
	int m_playerUfo;
	int m_playerWave;
	int m_playerRobot;
	int m_playerSpider;
	int m_playerSwing;
	int m_playerJetpack;
	int m_playerStreak;
	bool m_glowEnabled;
	int m_playerExplosion;
	int m_modBadge;
	int m_globalRank;
	int m_friendReqStatus;
	int m_newMsgCount;
	int m_friendReqCount;
	int m_newFriendCount;
	bool m_newFriendRequest;
};
class GManager : public cocos2d::CCNode {
public:
    //TodoReturn not implemented
    void getCompressedSaveString() {};
    //TodoReturn not implemented
    void getSaveString() {};
    //TodoReturn not implemented
    void load() {};
    //TodoReturn not implemented
    void loadDataFromFile(std::string const& p0) {};
    //TodoReturn not implemented
    void loadFromCompressedString(std::string& p0) {};
    //TodoReturn not implemented
    void loadFromString(std::string& p0) {};
    inline void save() {
        saveGMTo(m_fileName);
    }
    //TodoReturn not implemented
    void saveData(DS_Dictionary* p0, std::string p1) {};
    //0x47580 TodoReturn
    void saveGMTo(std::string p0) {};
    //TodoReturn not implemented
    void tryLoadData(DS_Dictionary* p0, std::string const& p1) {};
    inline GManager() {}
    // not implemented
    virtual bool init() {};
    //0x472c0 TodoReturn
    virtual void setup() {};
    //TodoReturn not implemented
    virtual void encodeDataTo(DS_Dictionary* p0) {};
    //TodoReturn not implemented
    virtual void dataLoaded(DS_Dictionary* p0) {};
    //TodoReturn not implemented
    virtual void firstLoad() {};
    std::string m_fileName;
    bool m_setup;
    bool m_saved;
    bool m_quickSave;
};
class UIButtonConfig {
public:
    //0x120660 TodoReturn
    void reset() {};
    //not implemented TodoReturn
    void resetOneBtn() {};
    PAD(40);
};
class GameManager : public GManager {
public:
    //0x121540
    static GameManager* sharedState() {
        addrViaPattern("?????? ? ? ? ? 64 a1 ? ? ? ? 50 51 a1 ? ? ? ? 33 c5 50 8d 45 ? 64 a3 ? ? ? ? a1 ? ? ? ? 85 c0 75 ? 68 ? ? ? ? ff 15 ? ? ? ? 83 c4 ? 89 45 ? c7 45 ? ? ? ? ? 85 c0 74 ? 8b c8 e8 ? ? ? ? 8b c8 eb ? 33 c9 c7 45 ? ? ? ? ? 8b 01 89 0d ? ? ? ? ff 50 ? a1 ? ? ? ? 8b 4d ? 64 89 0d ? ? ? ? 59 8b e5 5d c3 cc cc cc cc cc 55 8b ec 83 e4 ? 83 ec");
        return cast(GameManager*, __stdcall*, (), (), addr);
    };
    //not implemented
    void accountStatusChanged() {};
    //0x1270f0 TodoReturn
    void activeIconForType(IconType p0) {};
    //0x14da60 TodoReturn
    void addCustomAnimationFrame(int p0, int p1, std::string p2, std::string p3) {};
    //not implemented TodoReturn
    void addDuplicateLastFrame(int p0) {};
    //0x14d8c0
    TodoReturn addGameAnimation(int p0, int p1, float p2, std::string p3, std::string p4, int p5) {};
    //addIconDelegate not implemented
    TodoReturn addIconDelegate(cocos2d::CCObject* p0, int p1) {};
    //0x128ea0
    TodoReturn addNewCustomObject(std::string p0) {};
    //addToGJLog not implemented
    TodoReturn addToGJLog(cocos2d::CCString* p0) {};
    //applicationDidEnterBackground not implemented
    TodoReturn applicationDidEnterBackground() {};
    //0x12ded0
    TodoReturn applicationWillEnterForeground() {};
    //0x1278d0
    TodoReturn calculateBaseKeyForIcons() {};
    //canShowRewardedVideo not implemented
    TodoReturn canShowRewardedVideo() {};
    //0x1234f0
    TodoReturn checkSteamAchievementUnlock() {};
    //0x1297d0
    TodoReturn checkUsedIcons() {};
    //claimItemsResponse not implemented
    TodoReturn claimItemsResponse(std::string p0) {};
    //clearGJLog not implemented
    TodoReturn clearGJLog() {};
    //0x126090
    static cocos2d::ccColor3B colorForIdx(int p0) {
        addrViaPattern("????? ? 83 f8 ? 0f 87 ? ? ? ? ff 24 85 ? ? ? ? 8b 45");
        return cast(
            cocos2d::ccColor3B,
            __stdcall*,
            (int), (p0),
            addr
        )
    };
    //colorForPos not implemented
    TodoReturn colorForPos(int p0) {};
    //0x122350
    TodoReturn colorKey(int p0, UnlockType p1) {};
    //0x122b50
    TodoReturn completedAchievement(std::string p0) {};
    //0x127270
    TodoReturn countForType(IconType p0) {};
    //defaultFrameForAnimation not implemented
    TodoReturn defaultFrameForAnimation(int p0) {};
    //defaultYOffsetForBG2 not implemented
    TodoReturn defaultYOffsetForBG2(int p0) {};
    //didExitPlayscene not implemented
    TodoReturn didExitPlayscene() {};
    //0x12de10
    TodoReturn doQuickSave() {};
    //dpadConfigToString not implemented
    TodoReturn dpadConfigToString(UIButtonConfig& p0) {};
    //eventUnlockFeature not implemented
    TodoReturn eventUnlockFeature(char const* p0) {};
    //0x1219f0
    TodoReturn fadeInMenuMusic() {};
    //0x121a60
    TodoReturn fadeInMusic(std::string p0) {};
    //0x127ed0
    TodoReturn finishedLoadingBGAsync(cocos2d::CCObject* p0) {};
    //finishedLoadingGAsync not implemented
    TodoReturn finishedLoadingGAsync(int p0) {};
    //finishedLoadingGAsync1 not implemented
    TodoReturn finishedLoadingGAsync1(cocos2d::CCObject* p0) {};
    //finishedLoadingGAsync2 not implemented
    TodoReturn finishedLoadingGAsync2(cocos2d::CCObject* p0) {};
    //finishedLoadingIconAsync not implemented
    TodoReturn finishedLoadingIconAsync(cocos2d::CCObject* p0) {};
    //finishedLoadingMGAsync not implemented
    TodoReturn finishedLoadingMGAsync(int p0) {};
    //finishedLoadingMGAsync1 not implemented
    TodoReturn finishedLoadingMGAsync1(cocos2d::CCObject* p0) {};
    //finishedLoadingMGAsync2 not implemented
    TodoReturn finishedLoadingMGAsync2(cocos2d::CCObject* p0) {};
    //followTwitch not implemented
    TodoReturn followTwitch() {};
    //followTwitter not implemented
    TodoReturn followTwitter() {};
    //framesForAnimation not implemented
    TodoReturn framesForAnimation(int p0) {};
    //frameTimeForAnimation not implemented
    TodoReturn frameTimeForAnimation(int p0) {};
    //generateSecretNumber not implemented
    TodoReturn generateSecretNumber() {};
    //getBGTexture not implemented
    TodoReturn getBGTexture(int p0) {};
    //getFontFile not implemented
    TodoReturn getFontFile(int p0) {};
    //0x127c30
    TodoReturn getFontTexture(int p0) {};
    //0x128730
    bool getGameVariable(char const* p0) {};
    //getGTexture not implemented
    TodoReturn getGTexture(int p0) {};
    //getIconRequestID not implemented
    TodoReturn getIconRequestID() {};
    //0x128c80
    int getIntGameVariable(char const* p0) {};
    //0x1216e0
    TodoReturn getMenuMusicFile() {};
    //getMGTexture not implemented
    TodoReturn getMGTexture(int p0) {};
    //0x128d70
    TodoReturn getNextUniqueObjectKey() {};
    //0x128de0
    TodoReturn getNextUsedKey(int p0, bool p1) {};
    //getOrderedCustomObjectKeys not implemented
    TodoReturn getOrderedCustomObjectKeys() {};
    //0x1217b0
    TodoReturn getPracticeMusicFile() {};
    //0x128a20
    TodoReturn getUGV(char const* p0) {};
    //0x122690
    TodoReturn getUnlockForAchievement(std::string p0, int& p1, UnlockType& p2) {};
    //groundHasSecondaryColor not implemented
    TodoReturn groundHasSecondaryColor(int p0) {};
    //iconAndTypeForKey not implemented
    TodoReturn iconAndTypeForKey(int p0, int& p1, int& p2) {};
    //0x121d30
    TodoReturn iconKey(int p0, IconType p1) {};
    //0x122090
    UnlockType iconTypeToUnlockType(IconType p0) {};
    //0x122490
    bool isColorUnlocked(int p0, UnlockType p1) {};
    //isIconLoaded not implemented
    bool isIconLoaded(int p0, int p1) {};
    //0x121f90
    bool isIconUnlocked(int p0, IconType p1) {};
    //itemPurchased not implemented
    TodoReturn itemPurchased(char const* p0) {};
    //joinDiscord not implemented
    TodoReturn joinDiscord() {};
    //joinReddit not implemented
    TodoReturn joinReddit() {};
    //Out of line
    int keyForIcon(int iconIdx, int iconEnum) {};
    //levelIsPremium not implemented
    TodoReturn levelIsPremium(int p0, int p1) {};
    //likeFacebook not implemented
    TodoReturn likeFacebook() {};
    //0x127dc0
    void loadBackground(int p0) {};
    //0x127e60
    TodoReturn loadBackgroundAsync(int p0) {};
    //0x127c80
    TodoReturn loadDeathEffect(int p0) {};
    //loadDpadFromString not implemented
    TodoReturn loadDpadFromString(UIButtonConfig& p0, std::string p1) {};
    //0x12af80
    TodoReturn loadDPadLayout(int p0, bool p1) {};
    //0x127ba0
    TodoReturn loadFont(int p0) {};
    //0x1281f0
    void loadGround(int p0) {};
    //loadGroundAsync not implemented
    TodoReturn loadGroundAsync(int p0) {};
    //0x127440
    cocos2d::CCTexture2D* loadIcon(int p0, int p1, int p2) {};
    //loadIconAsync not implemented
    TodoReturn loadIconAsync(int p0, int p1, int p2, cocos2d::CCObject* p3) {};
    //0x127f50
    void loadMiddleground(int p0) {};
    //loadMiddlegroundAsync not implemented
    TodoReturn loadMiddlegroundAsync(int p0) {};
    //loadVideoSettings not implemented
    TodoReturn loadVideoSettings() {};
    //0x122610
    TodoReturn lockColor(int p0, UnlockType p1) {};
    //0x1222d0
    TodoReturn lockIcon(int p0, IconType p1) {};
    //logLoadedIconInfo not implemented
    TodoReturn logLoadedIconInfo() {};
    //0x1270d0
    TodoReturn openEditorGuide() {};
    //0x121890
    TodoReturn playMenuMusic() {};
    //0x121b40
    TodoReturn playSFXTrigger(SFXTriggerGameObject* p0) {};
    //0x12b720
    TodoReturn prepareDPadSettings() {};
    //printGJLog not implemented
    TodoReturn printGJLog() {};
    //0x12e3e0
    TodoReturn queueReloadMenu() {};
    //rateGame not implemented
    TodoReturn rateGame() {};
    //0x129ce0
    void recountUserStats(std::string p0) {};
    //0x12e4b0
    void reloadAll(bool switchingModes, bool toFullscreen, bool borderless, bool unused) {};
    //Out of line
    void reloadAll(bool switchingModes, bool toFullscreen, bool unused) {};
    //0x12e540
    TodoReturn reloadAllStep2() {};
    //0x12e6a0
    TodoReturn reloadAllStep3() {};
    //0x12e740
    TodoReturn reloadAllStep4() {};
    //0x12e7b0
    TodoReturn reloadAllStep5() {};
    //reloadMenu not implemented
    TodoReturn reloadMenu() {};
    //removeCustomObject not implemented
    TodoReturn removeCustomObject(int p0) {};
    //0x127370
    TodoReturn removeIconDelegate(int p0) {};
    //reorderKey not implemented
    TodoReturn reorderKey(int p0, bool p1) {};
    //0x1234a0
    TodoReturn reportAchievementWithID(char const* p0, int p1, bool p2) {};
    //0x122d50
    TodoReturn reportPercentageForLevel(int p0, int p1, bool p2) {};
    //resetAchievement not implemented
    TodoReturn resetAchievement(std::string p0) {};
    //resetAdTimer not implemented
    TodoReturn resetAdTimer() {};
    //resetAllIcons not implemented
    TodoReturn resetAllIcons() {};
    //resetCoinUnlocks not implemented
    TodoReturn resetCoinUnlocks() {};
    //resetDPadSettings not implemented
    TodoReturn resetDPadSettings(bool p0) {};
    //0x12e800
    TodoReturn resolutionForKey(int p0) {};
    //0x12e110
    TodoReturn returnToLastScene(GJGameLevel* p0) {};
    //rewardedVideoAdFinished not implemented
    TodoReturn rewardedVideoAdFinished(int p0) {};
    //rewardedVideoHidden not implemented
    TodoReturn rewardedVideoHidden() {};
    //rewardedVideoHiddenDelayed not implemented
    TodoReturn rewardedVideoHiddenDelayed() {};
    //safePopScene not implemented
    TodoReturn safePopScene() {};
    //saveAdTimer not implemented
    TodoReturn saveAdTimer() {};
    //0x12ac70
    TodoReturn saveDPadLayout(int p0, bool p1) {};
    //0x1284e0
    void setGameVariable(char const* p0, bool p1) {};
    //setHasRatingPower not implemented
    void setHasRatingPower(int p0) {};
    //0x128b80
    void setIntGameVariable(char const* p0, int p1) {};
    //setPlayerUserID not implemented
    void setPlayerUserID(int p0) {};
    //0x1288d0
    void setUGV(char const* p0, bool p1) {};
    //0x14b280
    TodoReturn setupGameAnimations() {};
    //0x1279a0
    std::string sheetNameForIcon(int p0, int p1) {};
    //shortenAdTimer not implemented
    TodoReturn shortenAdTimer(float p0) {};
    //shouldShowInterstitial not implemented
    TodoReturn shouldShowInterstitial(int p0, int p1, int p2) {};
    //showInterstitial not implemented
    TodoReturn showInterstitial() {};
    //showInterstitialForced not implemented
    TodoReturn showInterstitialForced() {};
    //showMainMenuAd not implemented
    TodoReturn showMainMenuAd() {};
    //startUpdate not implemented
    TodoReturn startUpdate() {};
    //stringForCustomObject not implemented
    TodoReturn stringForCustomObject(int p0) {};
    //subYouTube not implemented
    TodoReturn subYouTube() {};
    //switchCustomObjects not implemented
    TodoReturn switchCustomObjects(int p0, int p1) {};
    //switchScreenMode not implemented
    TodoReturn switchScreenMode(bool p0, bool p1) {};
    //syncPlatformAchievements not implemented
    TodoReturn syncPlatformAchievements() {};
    //toggleGameVariable not implemented
    TodoReturn toggleGameVariable(char const* p0) {};
    //tryCacheAd not implemented
    TodoReturn tryCacheAd() {};
    //tryShowInterstitial not implemented
    TodoReturn tryShowInterstitial(int p0, int p1, int p2) {};
    //0x127d40
    TodoReturn unloadBackground() {};
    //0x1276b0
    TodoReturn unloadIcon(int p0, int p1, int p2) {};
    //0x127870
    TodoReturn unloadIcons(int p0) {};
    //0x122560
    TodoReturn unlockColor(int p0, UnlockType p1) {};
    //unlockedPremium not implemented
    TodoReturn unlockedPremium() {};
    //0x122220
    TodoReturn unlockIcon(int p0, IconType p1) {};
    //0x122190
    TodoReturn unlockTypeToIconType(int p0) {};
    //0x12ec60
    TodoReturn updateCustomFPS() {};
    //updateMusic not implemented
    TodoReturn updateMusic() {};
    //verifyAchievementUnlocks not implemented
    TodoReturn verifyAchievementUnlocks() {};
    //verifyCoinUnlocks not implemented
    TodoReturn verifyCoinUnlocks() {};
    //verifyStarUnlocks not implemented
    TodoReturn verifyStarUnlocks() {};
    //verifySyncedCoins not implemented
    TodoReturn verifySyncedCoins() {};
    //videoAdHidden not implemented
    TodoReturn videoAdHidden() {};
    //videoAdShowed not implemented
    TodoReturn videoAdShowed() {};
    //update not implemented
    virtual void update(float p0) {};
    //0x1215c0
    virtual bool init() {};
    //0x12d480
    virtual TodoReturn encodeDataTo(DS_Dictionary* p0) {};
    //0x12b830
    virtual TodoReturn dataLoaded(DS_Dictionary* p0) {};
    //0x12cb20
    virtual TodoReturn firstLoad() {};
    cocos2d::CCDictionary* m_unkAnimationDict;
    cocos2d::CCDictionary* m_unkAnimationDict2;
    cocos2d::CCDictionary* m_frameTimeForAnimation;
    cocos2d::CCDictionary* m_framesForAnimation;
    cocos2d::CCDictionary* m_defaultFrames;
    bool m_switchModes;
    bool m_toFullscreen;
    bool m_reloading;
    bool m_unkBool1;
    bool m_unkBool2;
    bool m_vsyncEnabled;
    cocos2d::CCDictionary* m_valueKeeper;
    cocos2d::CCDictionary* m_unlockValueKeeper;
    cocos2d::CCDictionary* m_customObjectDict;
    double m_adTimer;
    double m_adCache;
    bool m_unkBool3;
    int m_unkSize4_1;
    double m_unkDouble2;
    int m_unkSize4_2;
    int m_unkSize4_3;
    bool m_loaded;
    bool m_googlePlaySignedIn;
    std::string m_unknownString;
    int m_unkSize4_4;
    PlayLayer* m_playLayer;
    LevelEditorLayer* m_levelEditorLayer;
    GJBaseGameLayer* m_gameLayer;
    void* m_unkPtr;
    MenuLayer* m_menuLayer;
    bool m_inMenuLayer;
    void* m_unknownVariable;
    bool m_unknownBool3;
    bool m_unknownPlayLayerBool;
    bool m_unknownBool4;
    bool m_unknownBool5;
    std::string m_playerUDID;
    std::string m_playerName;
    bool m_commentsEnabled;
    SeedValueRSV m_playerUserID;
    float m_bgVolume;
    float m_sfxVolume;
    float m_timeOffset;
    bool m_ratedGame;
    bool m_clickedFacebook;
    bool m_clickedTwitter;
    bool m_clickedYouTube;
    bool m_clickedTwitch;
    bool m_clickedDiscord_;
    bool m_clickedReddit;
    double m_socialsDuration;
    bool m_showedAd;
    bool m_unknownBool;
    bool m_editorEnabled;
    int m_sceneEnum;
    bool m_searchObjectBool;
    SeedValueRSV m_playerFrame;
    SeedValueRSV m_playerShip;
    SeedValueRSV m_playerBall;
    SeedValueRSV m_playerBird;
    SeedValueRSV m_playerDart;
    SeedValueRSV m_playerRobot;
    SeedValueRSV m_playerSpider;
    SeedValueRSV m_playerSwing;
    SeedValueRSV m_playerColor;
    SeedValueRSV m_playerColor2;
    SeedValueRSV m_playerGlowColor;
    SeedValueRSV m_playerStreak;
    SeedValueRSV m_playerShipFire;
    SeedValueRSV m_playerDeathEffect;
    SeedValueRSV m_playerJetpack;
    SeedValueRS m_chk;//SeedValueSR
    SeedValueRS m_secretNumber;//SeedValueSR
    bool m_playerGlow;
    IconType m_playerIconType;
    bool m_everyPlaySetup;
    bool m_showSongMarkers;
    bool m_showBPMMarkers;
    bool m_recordGameplay;
    bool m_showProgressBar;
    bool m_performanceMode;
    bool m_unkBool4;
    bool m_clickedGarage;
    bool m_clickedEditor;
    bool m_clickedName;
    bool m_clickedPractice;
    bool m_showedEditorGuide;
    bool m_showedRateDiffDialog;
    bool m_showedRateStarDialog;
    bool m_showedLowDetailDialog;
    void* m_unkPtr2;
    void* m_unkPtr3;
    int m_unkSize4_5;
    int m_unkSize4_6;
    int m_unkSize4_7;
    int m_unkSize4_8;
    int m_loadedBgID;
    int m_loadedGroundID;
    int m_loadedMG;
    int m_loadedFont;
    int m_loadedDeathEffect;
    bool m_loadingBG;
    bool m_loadingG;
    bool m_loadingG1;
    bool m_finishedLoadingG1;
    bool m_shouldLoadG1;
    bool m_finishedLoadingMG1;
    bool m_finishedLoadingMG2;
    bool m_unkBool5;
    int m_unkSize4_9;
    int m_unkSize4_10;
    int m_unkSize4_11;
    int m_bootups;
    bool m_hasRatedGame;
    bool m_unkBool6;
    bool m_shouldLoadUnlockValueKeeper;
    bool m_unkBool7;
    bool m_unkBool8;
    SeedValueRSV m_hasRP;
    bool m_canGetLevelSaveData;
    int m_resolution;
    int m_texQuality;
    bool m_somethingInMenuLayer;
    void* m_unkPtr4;
    bool m_unkBool9;
    int m_unkSize4_12;
    int m_unkSize4_13;
    bool m_unkBool10;
    int m_unkSize4_14;
    bool m_disableThumbstick;
    float m_customFPSTarget;
    bool m_unkBool11;
    int m_customMenuSongID;
    int m_customPracticeSongID;
    std::map<int, int> m_loadIcon;
    std::map<int, std::map<int, int>> m_loadIcon2;
    std::map<int, bool> m_isIconBeingLoaded;
    std::array<int, 9>* m_keyStartForIcon;
    void* m_somethingKeyForIcon;
    void* m_idk;
    std::map<int, std::vector<cocos2d::CCObject*>> m_iconDelegates;
    int m_iconRequestID;
    cocos2d::CCArray* m_unkArray;
    void* m_someAdPointer;
    int m_unkSize4_15;
    int m_unkSize4_16;
    int m_unkSize4_17;
    UIButtonConfig m_dpad1;
    UIButtonConfig m_dpad2;
    UIButtonConfig m_dpad3;
    UIButtonConfig m_dpad4;
    UIButtonConfig m_dpad5;
    std::string m_dpadLayout1;
    std::string m_dpadLayout2;
    std::string m_dpadLayout3;
    std::string m_dpadLayoutDual1;
    std::string m_dpadLayoutDual2;
    std::string m_dpadLayoutDual3;
    int m_unkSize4_18;
    int m_unkSize4_19;
    int m_unkSize4_20;
    bool m_unkBool12;
};
#endif

//layers for real
#if 1
class FLAlertLayer : public cocos2d::CCNodeRGBA, cocos2d::CCLayer {
public:
	cocos2d::CCMenu* m_buttonMenu;
	FLAlertLayerProtocol* m_alertProtocol;
	cocos2d::CCNode* m_scene;
	bool m_reverseKeyBack;
	cocos2d::ccColor3B m_color;
	cocos2d::CCLayer* m_mainLayer;
	int m_ZOrder;
	bool m_noElasticity;
	cocos2d::ccColor3B m_color2;
	ButtonSprite* m_button1;
	ButtonSprite* m_button2;
	ScrollingLayer* m_scrollingLayer;
	int m_controlConnected;
	bool m_containsBorder;
	bool m_noAction;
	int m_joystickConnected;
	bool m_forcePrioRegistered;
	virtual void show() {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(base + 0x31cd0)(this);
	}
};
class ProfilePage : public FLAlertLayer {
public:
	GJUserScore* m_score;
	int m_accountID;
	bool m_ownProfile;
	std::string m_profileKey;
	cocos2d::CCLabelBMFont* m_somethingWentWrong;
	cocos2d::CCLabelBMFont* m_usernameLabel;
	cocos2d::CCLayer* m_list;//GJCommentListLayer
	CCMenuItemSpriteExtra* m_rightArrow;
	CCMenuItemSpriteExtra* m_leftArrow;
	CCMenuItemSpriteExtra* m_followBtn;
	void* m_unk;
	cocos2d::CCArray* m_buttons;
	cocos2d::CCArray* m_arrayWithUsernameLabel;
	int m_itemCount;
	int m_pageStartIdx;
	int m_pageEndIdx;
	int m_page;
	cocos2d::CCLayer* m_circle;//LoadingCircle
	void* m_popupDelegate;
	CCMenuItemSpriteExtra* m_refreshBtn;
};
#endif

#endif
