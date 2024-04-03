#ifndef __GD_H__
#define __GD_H__

#include <cocos2d.h>
#include <cocos-ext.h>
#include <patterns.hpp>

inline auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
inline auto libcocos2d = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));

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
namespace gd {
    struct string {
        union {
            char inline_data[16];
            char* ptr;
        } m_data;
        size_t m_size = 0;
        size_t m_capacity = 15;
        // TODO:
        // ~string() = delete;
        ~string() {
            if (m_capacity > 15) {
                delete m_data.ptr;
                m_capacity = 15;
            }
            m_data.ptr = nullptr;
            m_size = 0;
        }
        string(const char* data, size_t size) {
            // reinterpret_cast<void*(__thiscall*)(void*, const char*, size_t)>(base + 0xf840)(this, data, size);
            this->assign(data, size);
        }
        size_t size() const { 
            return m_size; 
        }
        string& assign(const char* data, size_t size) {
            if (m_capacity > 15) {
                delete m_data.ptr;
                m_capacity = 15;
                m_data.inline_data[0] = 0;
                m_size = 0;
            }
            //55 8b ec 53 8b 5d ? 56 8b f1 85 db (gd2113 rva 0xf840)
            addrViaPattern(
                "55 8b ec 53 8b 5d ? 56 8b f1 85 db"
            );
            reinterpret_cast<void* (__thiscall*)(void*, const char*, size_t)>(addr)(this, data, size);
            return *this;
        }
        string& operator=(const std::string& other) {
            return this->assign(other.c_str(), other.size());
        }
        string& operator=(const string& other) {
            return this->assign(other.c_str(), other.size());
        }
        char* data() {
            if (m_capacity <= 15) return m_data.inline_data;
            return m_data.ptr;
        }
        const char* data() const { 
            return c_str(); 
        }
        const char* c_str() const {
            if (m_capacity <= 15) return m_data.inline_data;
            return m_data.ptr;
        }
        std::string to_str() const {
            return std::string(c_str(), size());
        }
        std::string_view to_sv() const {
            return std::string_view(c_str(), size());
        }
        operator std::string() const { 
            return to_str(); 
        }
        operator std::string_view() const { 
            return to_sv(); 
        }
    };
    static_assert(sizeof(string) == 24, "sizeof(gd::string) != 24, something went wrong..");
}
//objects and other classes
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
class CCCircleWave : public cocos2d::CCNode {
public:
    PAD(0x11);
    cocos2d::ccColor3B m_color;
};
class CCSpritePlus : public cocos2d::CCSprite {
public:
    cocos2d::CCArray* m_followers;
    CCSpritePlus* m_followingSprite;
    bool m_hasFollower;
    bool m_propagateScaleChanges;
    bool m_propagateFlipChanges;
};
class GameObject : public CCSpritePlus {};
class PlayerObject : public GameObject {
public:
    cocos2d::CCNode* m_mainLayer;
    PAD(0x44);
    cocos2d::CCNode* m_unk4e4;
    cocos2d::CCDictionary* m_unk4e8;
    cocos2d::CCDictionary* m_unk4ec;
    cocos2d::CCDictionary* m_unk4f0;
    cocos2d::CCDictionary* m_unk4f4;
    PAD(0x20);
    float m_unk518;
    bool m_unk51c;
    bool m_unk51d;
    bool m_unk51e;
    bool m_unk51f;
    PAD(0x4);
    GameObject* m_collidedObject;
    PAD(0x40);
    float m_unk568;
    cocos2d::CCSprite* m_unk56c;
    PAD(0x4);
    GameObject* m_unk574;
    GameObject* m_unk578;
    PAD(0x8);
    float unk_584;
    int unk_588; // seems to always be 0, but when you respawn it's -1 until you move at least 1 block from the respawn place
    PAD(0x4);
    cocos2d::CCArray* m_particleSystems;
    std::unordered_map<int, GJPointDouble> m_unk594; // insertions are in PlayerObject::rotateGameplayObject
    std::unordered_map<int, GameObject*> m_unk5b4;
    float m_unk5d4;
    float m_rotationSpeed;
    float m_unk5dc;
    bool m_isRotating;
    bool m_unk5e1;
    bool m_hasGlow;
    bool m_isHidden;
    int m_hasGhostTrail;
    GhostTrailEffect* m_ghostTrail;
    cocos2d::CCSprite* m_iconSprite;
    cocos2d::CCSprite* m_iconSpriteSecondary;
    cocos2d::CCSprite* m_iconSpriteWhitener;
    cocos2d::CCSprite* m_iconGlow;
    cocos2d::CCSprite* m_vehicleSprite;
    cocos2d::CCSprite* m_vehicleSpriteSecondary;
    cocos2d::CCSprite* m_unk604;
    cocos2d::CCSprite* m_vehicleSpriteWhitener;
    cocos2d::CCSprite* m_vehicleGlow;
    PlayerFireBoostSprite* m_swingFireMiddle;
    PlayerFireBoostSprite* m_swingFireBottom;
    PlayerFireBoostSprite* m_swingFireTop;
    cocos2d::CCSprite* m_unk61c;
    cocos2d::CCMotionStreak* m_regularTrail;
    PAD(0x4);
    HardStreak* m_waveTrail;
    float m_unk62c;
    PAD(0x14);
    float m_unk644;
    float m_unk648;
    PAD(0xc);
    bool m_unk658;
    bool m_unk659;
    bool m_unk65a;
    bool m_unk65b; // midair ??
    bool m_unk65c;
    bool m_unk65d; // walking ???
    bool m_unk65e;
    bool m_unk65f;
    PAD(0x28);
    float m_unk688;
    float m_unk68c;
    PAD(0x12);
    bool m_unk6a2; // = GameManager::getGameVariable("0096")
    bool m_unk6a3; // = GameManager::getGameVariable("0100")
    PAD(0x18);
    int m_unk6c0;
    GameObject* m_objectSnappedTo;
    PAD(0x4);
    GJRobotSprite* m_robotSprite;
    GJSpiderSprite* m_spiderSprite;
    PAD(0x4);
    cocos2d::CCParticleSystemQuad* m_unk6dc;
    cocos2d::CCParticleSystemQuad* m_trailingParticles; // 0x6d8
    cocos2d::CCParticleSystemQuad* m_shipClickParticles; // 0x6dc
    cocos2d::CCParticleSystemQuad* m_unk6e8;
    cocos2d::CCParticleSystemQuad* m_ufoClickParticles; // 0x6e4
    cocos2d::CCParticleSystemQuad* m_robotBurstParticles;
    cocos2d::CCParticleSystemQuad* m_unk6f4;
    cocos2d::CCParticleSystemQuad* m_swingBurstParticles1; // 0x6f0
    cocos2d::CCParticleSystemQuad* m_swingBurstParticles2; // 0x6f4
    PAD(0x4);
    cocos2d::CCParticleSystemQuad* m_unk704;
    cocos2d::CCParticleSystemQuad* m_unk708;
    float m_unk70c;
    float m_unk710;
    PAD(0x64);
    bool m_hasCustomGlowColor;
    cocos2d::ccColor3B m_glowColor;
    PAD(0x24);
    double m_yVelocity;
    bool m_isOnSlope;
    bool m_wasOnSlope;
    PAD(0x7);
    bool m_isShip;
    bool m_isBird;
    bool m_isBall;
    bool m_isDart;
    bool m_isRobot;
    bool m_isSpider;
    bool m_isUpsideDown;
    bool m_isDead;
    bool m_isOnGround;
    bool m_isGoingLeft;
    bool m_isSideways;
    bool m_isSwing;
    PAD(0x10);
    float m_unk7c8;
    float m_unk7cc; // unsure if float
    float m_unk7d0;
    bool m_isDashing;
    PAD(0x8);
    float m_vehicleSize;
    float m_playerSpeed;
    float m_unk7e0;
    float m_unk7e4;
    cocos2d::CCPoint m_unk7e8;
    cocos2d::CCPoint m_unk7f0; // maybe m_lastPortalPos
    bool m_unk7f8;
    PAD(0x18);
    cocos2d::CCPoint m_lastGroundedPos;
    cocos2d::CCArray* m_touchingRings;
    int m_unk828;
    GameObject* m_lastActivatedPortal;
    bool m_unk814;
    bool m_unk815;
    cocos2d::ccColor3B m_playerColor1; // 0x816
    cocos2d::ccColor3B m_playerColor2; // 0x819
    cocos2d::CCPoint m_position;
    PAD(0x14);
    float m_unk838;
    PAD(0x4);
    bool m_gamevar0060;
    bool m_gamevar0061;
    bool m_gamevar0062;
    PAD(0x4);
    std::vector<float> m_unk880;
    PAD(0x1c);
    double m_platformerXVelocity;
    PAD(0x70);
    bool m_isPlatformer;
    int m_unk8ec;
    int m_unk8f0;
    int m_unk8f4;
    int m_unk8f8;
    float m_gravityMod;
    PAD(0x4);
    cocos2d::CCPoint m_unk904;
    PAD(0x4);
    std::map<int, bool> m_unk910;
    float m_unk918; // increments whenever you're midiar?
    float m_unk91c;
    PAD(0x4);
    std::map<int, bool> m_unk924;
    PAD(0x4);
    gd::string m_unk930; // this is always "run" ???
    bool m_unk948; // = getGameVariable("0123")
    PAD(0x3);
    int m_iconRequestID;
    cocos2d::CCSpriteBatchNode* m_unk950;
    cocos2d::CCSpriteBatchNode* m_unk954;
    cocos2d::CCArray* m_unk958;
    PlayerFireBoostSprite* m_robotFire;
    PAD(0x4);
    GJBaseGameLayer* m_gameLayer;
    cocos2d::CCLayer* m_parentLayer;
    GJActionManager* m_actionManager;
    PAD(0x4);
    float m_unk974;
    bool m_unk978;
    bool m_unk979; // = isItemEnabled(0xc, 0x12);
    bool m_unk97a; // = isItemEnabled(0xc, 0x13);
    bool m_unk97b; // = isItemEnabled(0xc, 0x14);
    PAD(0x4);
};
//types
enum class BoomListType {
    Default = 0x0,
    User = 0x2,
    Stats = 0x3,
    Achievement = 0x4,
    Level = 0x5,
    Level2 = 0x6,
    Comment = 0x7,
    Comment2 = 0x8,
    Comment3 = 0x9,
    Song = 0xc,
    Score = 0xd,
    MapPack = 0xe,
    CustomSong = 0xf,
    Comment4 = 0x10,
    User2 = 0x11,
    Request = 0x12,
    Message = 0x13,
    LevelScore = 0x14,
    Artist = 0x15,
    SmartTemplate = 0x16,
    SFX = 0x17,
    SFX2 = 0x18,
    CustomMusic = 0x19,
    Options = 0x1a,
    LevelList = 0x1b,
    Level3 = 0x1c,
    LevelList2 = 0x1d,
    LevelList3 = 0x1e,
    Level4 = 0x1f,
    LocalLevelScore = 0x21,
    URL = 0x22,
};
enum class CommentKeyType {
    Level = 0,
    User = 1,
    LevelList = 2
};
// Geode Addition
enum class PlaybackMode {
    Not = 0,
    Playing = 1,
    Paused = 2,
};
enum class GJGameEvent {
    None = 0,
    TinyLanding = 1,
    FeatherLanding = 2,
    SoftLanding = 3,
    NormalLanding = 4,
    HardLanding = 5,
    HitHead = 6,
    OrbTouched = 7,
    OrbActivated = 8,
    PadActivated = 9,
    GravityInverted = 10,
    GravityRestored = 11,
    NormalJump = 12,
    RobotBoostStart = 13,
    RobotBoostStop = 14,
    UFOJump = 15,
    ShipBoostStart = 16,
    ShipBoostEnd = 17,
    SpiderTeleport = 18,
    BallSwitch = 19,
    SwingSwitch = 20,
    WavePush = 21,
    WaveRelease = 22,
    DashStart = 23,
    DashStop = 24,
    Teleported = 25,
    PortalNormal = 26,
    PortalShip = 27,
    PortalBall = 28,
    PortalUFO = 29,
    PortalWave = 30,
    PortalRobot = 31,
    PortalSpider = 32,
    PortalSwing = 33,
    YellowOrb = 34,
    PinkOrb = 35,
    RedOrb = 36,
    GravityOrb = 37,
    GreenOrb = 38,
    DropOrb = 39,
    CustomOrb = 40,
    DashOrb = 41,
    GravityDashOrb = 42,
    SpiderOrb = 43,
    TeleportOrb = 44,
    YellowPad = 45,
    PinkPad = 46,
    RedPad = 47,
    GravityPad = 48,
    SpiderPad = 49,
    PortalGravityFlip = 50,
    PortalGravityNormal = 51,
    PortalGravityInvert = 52,
    PortalFlip = 53,
    PortalUnFlip = 54,
    PortalNormalScale = 55,
    PortalMiniScale = 56,
    PortalDualOn = 57,
    PortalDualOff = 58,
    PortalTeleport = 59,
    Checkpoint = 60,
    DestroyBlock = 61,
    UserCoin = 62,
    PickupItem = 63,
    CheckpointRespawn = 64,
    FallLow = 65,
    FallMed = 66,
    FallHigh = 67,
    FallVHigh = 68,
    JumpPush = 69,
    JumpRelease = 70,
    LeftPush = 71,
    LeftRelease = 72,
    RightPush = 73,
    RightRelease = 74,
    PlayerReversed = 75,
    FallSpeedLow = 76,
    FallSpeedMed = 77,
    FallSpeedHigh = 78
};
//layers
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
class GJDropDownLayer : public cocos2d::CCLayer {};;
class AccountHelpLayer : public cocos2d::CCLayer {};;
class AccountLayer : public cocos2d::CCLayer {};;
class AccountLoginLayer : public cocos2d::CCLayer {};;
class AccountRegisterLayer : public cocos2d::CCLayer {};;
class AchievementsLayer : public cocos2d::CCLayer {};;
class AudioEffectsLayer : public cocos2d::CCLayer {};;
class BoomListLayer : public cocos2d::CCLayer {};;
class BoomScrollLayer : public cocos2d::CCLayer {};;
class BrowseSmartTemplateLayer : public cocos2d::CCLayer {};;
class BrowseSmartKeyLayer : public cocos2d::CCLayer {};;
class CCBlockLayer : public cocos2d::CCLayer {};;
class CCContentLayer : public cocos2d::CCLayer {};;
class CreateGuidelinesLayer : public cocos2d::CCLayer {};;
class CreatorLayer : public cocos2d::CCLayer {};;
class CurrencyRewardLayer : public cocos2d::CCLayer {};;
class CustomizeObjectLayer : public cocos2d::CCLayer {};;
class CustomSongLayer : public cocos2d::CCLayer {};;
class DemonFilterSelectLayer : public cocos2d::CCLayer {};;
class DialogLayer : public cocos2d::CCLayer {};;
class DrawGridLayer : public cocos2d::CCLayer {};;
class EditLevelLayer : public cocos2d::CCLayer {};;
class GJOptionsLayer : public cocos2d::CCLayer {};;
class EditorOptionsLayer : public cocos2d::CCLayer {};;
class EditorPauseLayer : public cocos2d::CCLayer {};;
class EndLevelLayer : public cocos2d::CCLayer {};;
class ExtendedLayer : public cocos2d::CCLayer {};;
class FindBPMLayer : public cocos2d::CCLayer {};;
class GameLevelOptionsLayer : public cocos2d::CCLayer {};;
class GameOptionsLayer : public cocos2d::CCLayer {};;
class GauntletLayer : public cocos2d::CCLayer {};;
class GauntletSelectLayer : public cocos2d::CCLayer {};;
class GJAccountSettingsLayer : public cocos2d::CCLayer {};
class GJGameState {
public:
    float m_unk0;
    float m_unk4;
    cocos2d::CCPoint m_unk8;
    cocos2d::CCPoint m_unk10;
    cocos2d::CCPoint m_unk18;
    cocos2d::CCPoint m_unk20;
    cocos2d::CCPoint m_unk28;
    cocos2d::CCPoint m_unk30;
    cocos2d::CCPoint m_unk38;
    cocos2d::CCPoint m_unk40;
    cocos2d::CCPoint m_unk48;
    cocos2d::CCPoint m_unk50;
    cocos2d::CCPoint m_unk58;
    cocos2d::CCPoint m_unk60;
    cocos2d::CCPoint m_unk68;
    cocos2d::CCPoint m_unk70;
    cocos2d::CCPoint m_unk78;
    cocos2d::CCPoint m_unk80;
    cocos2d::CCPoint m_unk88;
    cocos2d::CCPoint m_unk90;
    cocos2d::CCPoint m_unk98;
    cocos2d::CCPoint m_unka0;
    cocos2d::CCPoint m_unka8;
    cocos2d::CCPoint m_unkb0;
    cocos2d::CCPoint m_unkb8;
    cocos2d::CCPoint m_unkc0;
    cocos2d::CCPoint m_unkc8;
    cocos2d::CCPoint m_unkd0;
    cocos2d::CCPoint m_unkd8;
    cocos2d::CCPoint m_unke0;
    cocos2d::CCPoint m_unke8;
    cocos2d::CCPoint m_unkf0;
    bool m_unkf8;
    int m_unkfc;
    bool m_unk100;
    int m_unk104;
    bool m_unk108;
    cocos2d::CCPoint m_unk10c;
    PAD(0x10);
    float m_unk124;
    float m_unk128;
    PAD(0x1c);
    float m_unk148;
    PAD(0x1c);
    bool m_unk168;
    bool m_unk169;
    bool m_unk16a;
    float m_unk16c;
    float m_unk170;
    float m_unk174;
    float m_unk178;
    int m_unk17c;
    int m_unk180;
    bool m_unk184;
    float m_unk188;
    float m_unk18c;
    int m_currentChannel;
    int m_unk194;
    std::unordered_map<int, int> m_unk198;
    std::unordered_map<int, bool> m_unk1b4;
    float m_unk1d0; // unsure types of all 4 floats
    float m_unk1d4;
    float m_unk1d8;
    float m_unk1dc;
    double m_unk1e0; // unsure type
    PAD(0x8);
    int m_unk1f8; // used in PlayLayer::getCurrentPercent
    PAD(0x18);
    cocos2d::CCPoint m_unk20c;
    PAD(0xa);
    bool m_isDualMode;
    PAD(0x5);
    std::unordered_map<int, GJValueTween> m_unk224;
    PAD(0x10);
    std::unordered_map<int, GameObjectPhysics> m_unk250;
    PAD(0x18);
    cocos2d::CCPoint m_unk284;
    int m_unk288;
    int m_unk28c;
    bool m_unk290;
    std::map<std::pair<int, int>, int> m_unk298;
    int m_unkidk;
    cocos2d::CCPoint m_unk2b8;
    cocos2d::CCPoint m_unk2c0;
    bool m_unk2c8;
    bool m_unk2c9;
    bool m_unk2ca;
    PAD(0x6);
    bool m_unk2d0;
    bool m_unk2d1;
    PAD(0x10);
    double m_unk2e4; // unsure type
    cocos2d::CCPoint m_unk2e8;
    PAD(0x4);
    std::unordered_map<int, EnhancedGameObject*> m_unk2f4;
    std::map<std::pair<GJGameEvent, int>, std::vector<EventTriggerInstance>> m_unk310;
    std::map<std::pair<GJGameEvent, int>, int> m_unk328;
    std::unordered_map<int, std::vector<EnterEffectInstance>> m_unk340;
    std::unordered_map<int, std::vector<EnterEffectInstance>> m_unk35c;
    std::vector<int> m_unk378;
    std::vector<int> m_unk384;
    std::vector<EnterEffectInstance> m_unk390;
    std::vector<EnterEffectInstance> m_unk39c;
    std::vector<EnterEffectInstance> m_unk3a8;
    std::vector<EnterEffectInstance> m_unk3b4;
    std::vector<EnterEffectInstance> m_unk3c0;
    int m_unk3cc;
    bool m_unk3e8;
    std::vector<AdvancedFollowInstance> m_unk3ec;
    std::vector<DynamicObjectAction> m_unk3f8;
    std::vector<DynamicObjectAction> m_unk404;
    bool m_unk410;
    bool m_unk411;
    PAD(0x4);
};
class GJBaseGameLayer : public cocos2d::CCLayer {
public:
    PAD(0x8);
    GJGameState m_gameState;
    GJGameLevel* m_level;
    PlaybackMode m_playbackMode;
    PAD(0x290);
    PlayerObject* m_player1;
    PlayerObject* m_player2;
    LevelSettingsObject* m_levelSettings;
    cocos2d::CCArray* m_objects;
    cocos2d::CCArray* m_unknownCB0;
    cocos2d::CCArray* m_unknownCB8;
    cocos2d::CCDictionary* m_unknownCC0;
    cocos2d::CCNode* m_unknownCC8;
    std::vector<GameObject*> m_unknownCD0;
    std::vector<GameObject*> m_unknownCE8;
    std::vector<GameObject*> m_unknownD00;
    std::vector<GameObject*> m_unknownD18;
    std::vector<GameObject*> m_unknownD30;
    std::unordered_map<int, int> m_unknownD48;
    std::vector<GameObject*> m_unknownD70;
    std::unordered_map<int, std::vector<GameObject*>> m_unknownD88;
    int m_unknownDB0;
    int m_unknownDB8;
    int m_unknownDBC;
    int m_unknownDC0;
    int m_unknownDC4;
    int m_unknownDC8;
    int m_unknownDCC;
    int m_unknownDD0;
    int m_unknownDD4;
    cocos2d::CCDictionary* m_groupDict;
    cocos2d::CCDictionary* m_staticGroupDict;
    cocos2d::CCDictionary* m_optimizedGroupDict;
    std::vector<cocos2d::CCArray*> m_groups;
    std::vector<cocos2d::CCArray*> m_staticGroups;
    std::vector<cocos2d::CCArray*> m_optimizedGroups;
    cocos2d::CCDictionary* m_unknownE38;
    cocos2d::CCDictionary* m_unknownE40;
    cocos2d::CCDictionary* m_unknownE48;
    cocos2d::CCArray* m_unknownE50;
    std::unordered_map<int, std::pair<int, int>> m_unknownE58;
    cocos2d::CCDictionary* m_unknownE80;
    float m_unknownE88;
    cocos2d::CCNode* m_unknownE90;
    cocos2d::CCNode* m_unknownE98;
    cocos2d::CCNode* m_unknownEA0;
    cocos2d::CCLayer* m_objectLayer;
};
class GJColorSetupLayer : public cocos2d::CCLayer {};;
class GJCommentListLayer : public cocos2d::CCLayer {};;
class GJGroundLayer : public cocos2d::CCLayer {};;
class GJFlyGroundLayer : public cocos2d::CCLayer {};;
class GJFollowCommandLayer : public cocos2d::CCLayer {};;
class GJGameLoadingLayer : public cocos2d::CCLayer {};;
class GJGarageLayer : public cocos2d::CCLayer {};;
class GJGradientLayer : public cocos2d::CCLayer {};;
class GJListLayer : public cocos2d::CCLayer {};;
class GJMGLayer : public cocos2d::CCLayer {};;
class GJMoreGamesLayer : public cocos2d::CCLayer {};;
class GJPathsLayer : public cocos2d::CCLayer {};;
class GJPFollowCommandLayer : public cocos2d::CCLayer {};;
class GJRotateCommandLayer : public cocos2d::CCLayer {};;
class GJShopLayer : public cocos2d::CCLayer {};;
class GraphicsReloadLayer : public cocos2d::CCLayer {};;
class InfoLayer : public FLAlertLayer {
public:
    GJGameLevel* m_level;
    GJUserScore* m_score;
    GJLevelList* m_levelList;
    gd::string m_commentKey;
    LoadingCircle* m_loadingCircle;
    cocos2d::CCLabelBMFont* m_pageLabel;
    cocos2d::CCLabelBMFont* m_noComments;
    GJCommentListLayer* m_list;
    CCMenuItemSpriteExtra* m_rightArrow;
    CCMenuItemSpriteExtra* m_leftArrow;
    CCMenuItemSpriteExtra* m_likeBtn;
    CCMenuItemSpriteExtra* m_timeBtn;
    CCMenuItemSpriteExtra* m_reportBtn;
    CCMenuItemSpriteExtra* m_commentsBtn;
    CCMenuItemSpriteExtra* m_refreshCommentsBtn;
    int m_itemCount;
    int m_pageStartIdx;
    int m_pageEndIdx;
    int m_page;
    bool m_canUpdateUserScore;
    CommentKeyType m_mode;
};
class KeybindingsLayer : public cocos2d::CCLayer {};;
class LeaderboardsLayer : public cocos2d::CCLayer {};;
class LevelAreaInnerLayer : public cocos2d::CCLayer {};;
class LevelAreaLayer : public cocos2d::CCLayer {};;
class LevelBrowserLayer : public cocos2d::CCLayer {};;
class LevelEditorLayer : public cocos2d::CCLayer {

    bool m_drawTriggerBoxes;
    bool m_showGrid;
    bool m_hideGridOnPlay;
    bool m_drawEffectLines;
    bool m_showGround;
    bool m_showDurationLines;
    bool m_increaseMaxUndoRedo;
    bool m_hideBackground;
    bool m_gv0120;
    bool m_layerLockingEnabled;
    bool m_unkBool4;
    bool m_previewParticles;
    bool m_previewAnimations;
    bool m_previewShaders;
    bool m_hideParticleIcons;
    bool m_unkBool5;
    bool m_playTestSmoothFix;

    // haven't verified the mac padding
    PAD(0xf);

    cocos2d::CCArray* m_unkArr0;
    cocos2d::CCArray* m_unkArr1;
    cocos2d::CCArray* m_unkArr2;
    cocos2d::CCArray* m_unkArr3;
    cocos2d::CCArray* m_unkArr4;
    cocos2d::CCArray* m_unkArr8;
    cocos2d::CCArray* m_unkArr11;
    cocos2d::CCArray* m_unkArr12;
    cocos2d::CCArray* m_unkArr13;
    cocos2d::CCDictionary* m_unkDict3;
    cocos2d::CCArray* m_unkArr5;

    PAD(0x8);

    cocos2d::CCDictionary* m_unkDict4;
    cocos2d::CCArray* m_unkArr7;
    bool m_unkBool3;
    bool m_unkBool2;
    SeedValueRSV m_coinCount;

    PAD(0x8);

    cocos2d::CCArray* m_unkArr6;

    PAD(0x4);

    cocos2d::CCDictionary* m_unkDict1;
    cocos2d::CCDictionary* m_unkDict2;
    bool m_unkBool0;
    bool m_unkBool1;
    short m_currentLayer;

    PAD(0x18);

    EditorUI* m_editorUI;
    cocos2d::CCArray* m_undoObjects;
    cocos2d::CCArray* m_redoObjects;
    SeedValueRSV m_objectCount;
    DrawGridLayer* m_drawGridLayer;
    bool m_unkBool;
    bool m_previewMode;

    PAD(0x86);

    std::vector<bool> m_lockedLayers;
};
class LevelFeatureLayer : public cocos2d::CCLayer {};;
class LevelInfoLayer : public cocos2d::CCLayer {
public:
    void* m_unk0;
    cocos2d::CCMenu* m_playBtnMenu;
    GJGameLevel* m_level;
    cocos2d::CCArray* m_coins;
    CCMenuItemSpriteExtra* m_likeBtn;
    CCMenuItemSpriteExtra* m_starRateBtn;
    CCMenuItemSpriteExtra* m_demonRateBtn;
    void* m_unk2;
    cocos2d::CCLabelBMFont* m_lengthLabel;
    cocos2d::CCLabelBMFont* m_downloadsLabel;
    cocos2d::CCLabelBMFont* m_likesLabel;
    cocos2d::CCLabelBMFont* m_orbsLabel;
    cocos2d::CCLabelBMFont* m_folderLabel;
    CCMenuItemSpriteExtra* m_cloneBtn;
    void* m_unk3;
    cocos2d::CCSprite* m_likesIcon;
    cocos2d::CCSprite* m_orbsIcon;
    int m_unk6; // always 3, maybe level type?
    int m_unk7;
    LoadingCircle* m_circle;
    GJDifficultySprite* m_difficultySprite;
    cocos2d::CCSprite* m_starsIcon;
    cocos2d::CCLabelBMFont* m_starsLabel;
    cocos2d::CCArray* m_icons;
    PAD(0x10);
    bool m_challenge;
    PAD(0x4);
    cocos2d::CCSprite* m_playSprite;
    void* m_unk11;
    CustomSongWidget* m_songWidget;
};
class LevelListLayer : public cocos2d::CCLayer {};;
class LevelOptionsLayer : public cocos2d::CCLayer {};;
class LevelOptionsLayer2 : public cocos2d::CCLayer {};;
class LevelSearchLayer : public cocos2d::CCLayer {};;
class LevelSelectLayer : public cocos2d::CCLayer {};;
class LevelSettingsLayer : public cocos2d::CCLayer {};;
class LikeItemLayer : public cocos2d::CCLayer {};;
class LoadingLayer : public cocos2d::CCLayer {
public:
    bool m_unknown;
    bool m_unknown2;
    int m_loadStep;
    cocos2d::CCLabelBMFont* m_caption;
    TextArea* m_textArea;
    cocos2d::CCSprite* m_sliderBar;
    float m_sliderGrooveXPos;
    float m_sliderGrooveHeight;
    bool m_fromRefresh;
};
class MapSelectLayer : public cocos2d::CCLayer {};;
class MenuGameLayer : public cocos2d::CCLayer {
public:
    bool m_unkBool1;
    float m_deltaCount;
    bool m_isDestroyingPlayer;
    int m_initCount;
    cocos2d::CCPoint* m_unused1;
    int m_unused2;
    PlayerObject* m_playerObject;
    cocos2d::CCSprite* m_backgroundSprite;
    GJGroundLayer* m_groundLayer;
    float m_backgroundSpeed;
};
class MenuLayer : public cocos2d::CCLayer {
public:
    //custom shit
    //returns mbo 340
    CCNode* getProfileButton() {
        return MBO(CCNode*, this, 340);
    }
    //find the MenuGameLayer
    MenuGameLayer* getMenuGameLayer() {
        MenuGameLayer* rtn;
        for (int i = 0; i < this->getChildrenCount(); i++) {
            auto obj = this->getChildren()->objectAtIndex(i);
            if (obj) {
                if (auto pMenuGameLayer = dynamic_cast<MenuGameLayer*>(obj)) {
                    rtn = pMenuGameLayer;
                }
            }
        }
        return rtn;
    }
    //returns getProfileButton() parent
    cocos2d::CCMenu* getSomeMenu() {
        return dynamic_cast<cocos2d::CCMenu*>(getProfileButton()->getParent());
    }
};
class MoreOptionsLayer : public cocos2d::CCLayer {};;
class MoreSearchLayer : public cocos2d::CCLayer {};;
class MoreVideoOptionsLayer : public cocos2d::CCLayer {};;
class MPLobbyLayer : public cocos2d::CCLayer {};;
class MultiplayerLayer : public cocos2d::CCLayer {};;
class NewgroundsInfoLayer : public cocos2d::CCLayer {};;
class NumberInputLayer : public cocos2d::CCLayer {};;
class OptionsLayer : public cocos2d::CCLayer {};;
class OptionsObject;
class OptionsScrollLayer : public cocos2d::CCLayer {};;
class ParentalOptionsLayer : public cocos2d::CCLayer {};;
class ParticlePreviewLayer : public cocos2d::CCLayer {};;
class PauseLayer : public cocos2d::CCLayer {};;
class PlayLayer : public GJBaseGameLayer {
public:

    PAD(0x84);
    float m_unksomefloat;
    PAD(0x24);
    cocos2d::CCArray* m_circleWaveArray;
    PAD(0x10);
    cocos2d::CCLabelBMFont* m_attemptLabel;
    PAD(0x8);
    cocos2d::CCSprite* m_progressBar;
    PAD(0x5c);
    bool m_endLayerStars;
    PAD(0xb8);

    void addCircle(CCCircleWave* cw) {
        m_circleWaveArray->addObject(cw);
    }
};
class RateDemonLayer : public cocos2d::CCLayer {};;
class RateLevelLayer : public cocos2d::CCLayer {};;
class RateStarsLayer : public cocos2d::CCLayer {};;
class RetryLevelLayer : public cocos2d::CCLayer {};;
class RewardUnlockLayer : public cocos2d::CCLayer {};;
class ScrollingLayer : public cocos2d::CCLayer {};;
class SecretLayer : public cocos2d::CCLayer {};
class SecretLayer2 : public cocos2d::CCLayer {};
class SecretLayer3 : public cocos2d::CCLayer {};
class SecretLayer4 : public cocos2d::CCLayer {};
class SecretNumberLayer : public cocos2d::CCLayer {};;
class SecretRewardsLayer : public cocos2d::CCLayer {};;
class SelectArtLayer : public cocos2d::CCLayer {};;
class SelectEventLayer : public cocos2d::CCLayer {};;
class SelectFontLayer : public cocos2d::CCLayer {};;
class SelectListIconLayer : public cocos2d::CCLayer {};;
class SelectPremadeLayer : public cocos2d::CCLayer {};;
class SelectSettingLayer : public cocos2d::CCLayer {};;
class SelectSFXSortLayer : public cocos2d::CCLayer {};;
class SetGroupIDLayer : public cocos2d::CCLayer {};;
class SetItemIDLayer : public cocos2d::CCLayer {};;
class SetTargetIDLayer : public cocos2d::CCLayer {};;
class SetupCoinLayer : public cocos2d::CCLayer {};;
class SetupSmartBlockLayer : public cocos2d::CCLayer {};;
class SetupSmartTemplateLayer : public cocos2d::CCLayer {};;
class ShaderLayer : public cocos2d::CCLayer {};;
class ShareCommentLayer : public cocos2d::CCLayer {};;
class ShareLevelLayer : public cocos2d::CCLayer {};;
class ShareLevelSettingsLayer : public cocos2d::CCLayer {};;
class ShareListLayer : public cocos2d::CCLayer {};;
class SlideInLayer : public cocos2d::CCLayer {};;
class SongInfoLayer : public cocos2d::CCLayer {};;
class SongOptionsLayer : public cocos2d::CCLayer {};;
class SongsLayer : public cocos2d::CCLayer {};;
class StatsLayer : public cocos2d::CCLayer {};;
class SupportLayer : public cocos2d::CCLayer {};;
class TopArtistsLayer : public cocos2d::CCLayer {};;
class TutorialLayer : public cocos2d::CCLayer {};;
class UILayer : public cocos2d::CCLayer {};;
class UIOptionsLayer : public cocos2d::CCLayer {};;
class UISaveLoadLayer : public cocos2d::CCLayer {};;
class URLViewLayer : public cocos2d::CCLayer {};;
class VideoOptionsLayer : public cocos2d::CCLayer {};;
class WorldSelectLayer : public cocos2d::CCLayer {};;
#endif
