from tools.logger import Logger
from basic.config import config, Config

logger_cfg = config.get('logger')
Logger.SAVE_PATH = Config.process_path(logger_cfg['save_dir'])